#include <iostream>
#include <utility>

// =========================================================================
// CONTROL BLOCK STRUCTURE FOR SHARED AND WEAK POINTERS
// =========================================================================
struct ControlBlock
{
    int share_cnt = { 1 };
    int weak_cnt = { 0 };
};

// Forward declaration of WeakPtr to be used in SharedPtr
template <typename T> class WeakPtr;

// =========================================================================
// SHAREDPTR IMPLEMENTATION
// =========================================================================
template <typename T>
class SharedPtr
{
private:
    T* m_pData { nullptr };
    ControlBlock* m_pCb { nullptr };

    // Allow SharedPtr to access the private constructor for template conversion and lock() implementation
    template<typename U> friend class SharedPtr;
    // Allow WeakPtr to access the private constructor for lock() implementation
    template<typename U> friend class WeakPtr;

    // Private backdoor constructor for WeakPtr::lock()
    SharedPtr(T* data, ControlBlock* cb) : m_pData(data), m_pCb(cb) {
        std::cout << "SharedPtr: Private constructor called for lock()\n";
        if (m_pCb) {
            m_pCb->share_cnt++;
        }
    }

    // Helper function to release ownership and manage control block cleanup
    void release() {
        std::cout << "SharedPtr: Releasing ownership\n";
        if (m_pCb) {
            m_pCb->share_cnt--;
            if (m_pCb->share_cnt == 0) {
                delete m_pData;
                m_pData = nullptr;

                // ONLY delete control block memory if no weak pointers remain!
                if (m_pCb->weak_cnt == 0) {
                    delete m_pCb;
                }
            }
            m_pCb = nullptr;
        }
    }

public:
    SharedPtr() = default; // Default constructor

    // Constructor from raw pointer
    explicit SharedPtr(T* data) : m_pData(data) {
        std::cout << "SharedPtr: Constructor from raw pointer called\n";
        if (m_pData) {
            m_pCb = new ControlBlock();
        }
    }

    // Copy Constructor (Same Type)
    SharedPtr(const SharedPtr& src) : m_pData(src.m_pData), m_pCb(src.m_pCb) {
        std::cout << "SharedPtr: Copy constructor called\n";
        if (m_pCb) {
            m_pCb->share_cnt++;
        }
    }

    // Template Conversion Copy Constructor (Polymorphic Upcasting)
    template <typename U>
    SharedPtr(const SharedPtr<U>& src) : m_pData(src.m_pData), m_pCb(src.m_pCb) {
        std::cout << "SharedPtr: Template conversion copy constructor called\n";
        if (m_pCb) {
            m_pCb->share_cnt++;
        }
    }

    // Move Constructor (Same Type)
    SharedPtr(SharedPtr&& src) noexcept : m_pData(std::exchange(src.m_pData, nullptr)), m_pCb(std::exchange(src.m_pCb, nullptr)) {
        std::cout << "SharedPtr: Move constructor called\n";
    }

    // Template Conversion Move Constructor
    template <typename U>
    SharedPtr(SharedPtr<U>&& src) noexcept : m_pData(std::exchange(src.m_pData, nullptr)), m_pCb(std::exchange(src.m_pCb, nullptr)) {
        std::cout << "SharedPtr: Template conversion move constructor called\n";
    }

    // Copy Assignment (Same Type)
    SharedPtr& operator = (const SharedPtr& src) {
        std::cout << "SharedPtr: Copy assignment operator called\n";
        if (this != &src) {
            if (src.m_pCb) src.m_pCb->share_cnt++;
            release();
            m_pData = src.m_pData;
            m_pCb = src.m_pCb;
        }
        return *this;
    }

    // Template Conversion Copy Assignment
    template <typename U>
    SharedPtr& operator = (const SharedPtr<U>& src) {
        std::cout << "SharedPtr: Template conversion copy assignment operator called\n";
        if (m_pCb != src.m_pCb) {
            if (src.m_pCb) src.m_pCb->share_cnt++;
            release();
            m_pData = src.m_pData;
            m_pCb = src.m_pCb;
        }
        return *this;
    }

    // Move Assignment (Same Type)
    SharedPtr& operator = (SharedPtr&& src) noexcept {
        std::cout << "SharedPtr: Move assignment operator called\n";
        if (this != &src) {
            release();
            m_pData = std::exchange(src.m_pData, nullptr);
            m_pCb = std::exchange(src.m_pCb, nullptr);
        }
        return *this;
    }

    // Template Conversion Move Assignment
    template <typename U>
    SharedPtr& operator = (SharedPtr<U>&& src) noexcept {
        std::cout << "SharedPtr: Template conversion move assignment operator called\n";
        if (m_pCb != src.m_pCb) {
            release();
            m_pData = std::exchange(src.m_pData, nullptr);
            m_pCb = std::exchange(src.m_pCb, nullptr);
        }
        return *this;
    }

    // Destructor
    ~SharedPtr() {
        std::cout << "SharedPtr: Destructor called\n";
        release();
    }

    // Returns the raw pointer to the managed object
    T* get() const {
        std::cout << "SharedPtr: get() called\n";
        return m_pData;
    }
    // Arrow operator to access members of the underlying object
    T* operator -> () const {
        std::cout << "SharedPtr: Arrow operator called\n";
        return m_pData;
    }
    // Dereference operator to access the underlying object
    T& operator * () const {
        std::cout << "SharedPtr: Dereference operator called\n";
        return *m_pData;
    }
    // Returns the number of SharedPtr instances managing the current object
    int use_count() const {
        std::cout << "SharedPtr: use_count() called\n";
        return m_pCb ? m_pCb->share_cnt : 0;
    }

    // Contextual boolean check (Mandatory for: if (sharedPtr) { ... })
    explicit operator bool() const {
        std::cout << "SharedPtr: bool operator called\n";
        return m_pData != nullptr;
    }
    // C++20 and above Single Comparison Operator
    // This single function automatically enables: ptr == nullptr, nullptr == ptr, ptr != nullptr, and nullptr != ptr!
    bool operator==(std::nullptr_t) const noexcept { return m_pData == nullptr; }
};

// =========================================================================
// WEAKPTR IMPLEMENTATION
// =========================================================================
template <typename T>
class WeakPtr
{
private:
    T* m_pData { nullptr };
    ControlBlock* m_pCb { nullptr };

    // Allow template conversion constructors and assignment operators in WeakPtr
    template<typename U> friend class WeakPtr;

    // Helper function to release ownership and manage control block cleanup
    void release() {
        std::cout << "WeakPtr: Releasing ownership\n";
        if (m_pCb) {
            m_pCb->weak_cnt--;
            if (m_pCb->share_cnt == 0 && m_pCb->weak_cnt == 0) {
                delete m_pCb;
            }
            m_pCb = nullptr;
        }
    }

public:
    WeakPtr() = default; // Default constructor
    // Constructor from SharedPtr (Same Type)
    WeakPtr(const SharedPtr<T>& p) : m_pData(p.m_pData), m_pCb(p.m_pCb) {
        std::cout << "WeakPtr: Constructor from SharedPtr called\n";
        if (m_pCb) m_pCb->weak_cnt++;
    }

    // Template Conversion Constructor from SharedPtr (Polymorphic Upcasting)
    template <typename U>
    WeakPtr(const SharedPtr<U>& p) : m_pData(p.m_pData), m_pCb(p.m_pCb) {
        std::cout << "WeakPtr: Template conversion constructor from SharedPtr called\n";
        if (m_pCb) m_pCb->weak_cnt++;
    }

    // Copy Constructor (Same Type)
    WeakPtr(const WeakPtr& src) : m_pData(src.m_pData), m_pCb(src.m_pCb) {
        std::cout << "WeakPtr: Copy constructor called\n";
        if (m_pCb) m_pCb->weak_cnt++;
    }

    // Template Conversion Copy Constructor (Polymorphic Upcasting)
    template <typename U>
    WeakPtr(const WeakPtr<U>& src) : m_pData(src.m_pData), m_pCb(src.m_pCb) {
        std::cout << "WeakPtr: Template conversion constructor called\n";
        if (m_pCb) m_pCb->weak_cnt++;
    }

    // Move Constructor (Same Type)
    WeakPtr(WeakPtr&& src) noexcept : m_pData(std::exchange(src.m_pData, nullptr)), m_pCb(std::exchange(src.m_pCb, nullptr)) {
        std::cout << "WeakPtr: Move constructor called\n";
    }

    // Template Conversion Move Constructor
    template <typename U>
    WeakPtr(WeakPtr<U>&& src) noexcept : m_pData(std::exchange(src.m_pData, nullptr)), m_pCb(std::exchange(src.m_pCb, nullptr)) {
        std::cout << "WeakPtr: Template conversion move constructor called\n";
    }

    // Copy Assignment (Same Type)
    WeakPtr& operator = (const WeakPtr& src) {
        std::cout << "WeakPtr: Copy assignment operator called\n";
        if (this != &src) {
            if (src.m_pCb) src.m_pCb->weak_cnt++;
            release();
            m_pData = src.m_pData;
            m_pCb = src.m_pCb;
        }
        return *this;
    }

    // Template Conversion Copy Assignment
    template <typename U>
    WeakPtr& operator = (const WeakPtr<U>& src) {
        std::cout << "WeakPtr: Template conversion copy assignment operator called\n";
        if (m_pCb != src.m_pCb) {
            if (src.m_pCb) src.m_pCb->weak_cnt++;
            release();
            m_pData = src.m_pData;
            m_pCb = src.m_pCb;
        }
        return *this;
    }

    // Destructor
    ~WeakPtr() {
        std::cout << "WeakPtr: Destructor called\n";
        release();
    }

    // Checks if the managed object has been deleted (i.e., if the SharedPtr has released ownership)
    bool expired() const {
        std::cout << "WeakPtr: expired() called\n";
        return (!m_pCb || m_pCb->share_cnt == 0);
    }

    // Attempts to create a SharedPtr from this WeakPtr. If the managed object has been deleted, returns an empty SharedPtr.
    SharedPtr<T> lock() const {
        std::cout << "WeakPtr: lock() called\n";
        if (expired()) return SharedPtr<T>();
        return SharedPtr<T>(m_pData, m_pCb);
    }
};

// =========================================================================
// UniquePtr IMPLEMENTATION
// =========================================================================
template <typename T>
class UniquePtr
{
private:
    T* m_pData = { nullptr };

    // Grant access to all internal pointers across different template types (like Base/Derived)
    template <typename U> friend class UniquePtr;

public:
    // 1. Default Constructor
    UniquePtr() {
        std::cout << "UniquePtr default ctor" << std::endl;
    }

    // 2. Acquisition Constructor (Added explicit to prevent hidden wrappers)
    explicit UniquePtr(T* data) : m_pData(data) {
        std::cout << "UniquePtr ctor" << std::endl;
    }

    // 3. Same-Type Move Constructor
    UniquePtr(UniquePtr&& src) noexcept : m_pData(std::exchange(src.m_pData, nullptr)) {
        std::cout << "UniquePtr move ctor" << std::endl;
    }

    // 🌟 4. TEMPLATE CONVERSION MOVE CONSTRUCTOR (Supports upcasting unique pointers)
    template <typename U>
    UniquePtr(UniquePtr<U>&& src) noexcept : m_pData(std::exchange(src.m_pData, nullptr)) {
        std::cout << "UniquePtr conversion move ctor" << std::endl;
        // Raw upcast (U* to T*) happens automatically here inside the assignment list!
    }

    // 5. Same-Type Move Assignment
    UniquePtr& operator=(UniquePtr&& src) noexcept {
        std::cout << "UniquePtr move assignment" << std::endl;
        if (this != &src) {
            delete m_pData;
            m_pData = std::exchange(src.m_pData, nullptr);
        }
        return *this;
    }

    // 🌟 6. TEMPLATE CONVERSION MOVE ASSIGNMENT (ptrBase = std::move(ptrDerived))
    template <typename U>
    UniquePtr& operator=(UniquePtr<U>&& src) noexcept {
        std::cout << "UniquePtr conversion move assignment" << std::endl;
        if (this->m_pData != src.m_pData) {
            delete m_pData;
            m_pData = std::exchange(src.m_pData, nullptr);
        }
        return *this;
    }

    // 7. Destructor
    ~UniquePtr() {
        delete m_pData; // calling 'delete' on nullptr is completely safe in C++
    }

    // Explicitly forbid copying to maintain exclusive unique ownership
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // Observers & Getters
    T* operator ->() const noexcept{
        return m_pData;
    }
    T& operator * () const {
        return *m_pData;
    }
    T* get() const noexcept {
        return m_pData;
    }
    T* release() noexcept {
        T* temp = m_pData;
        m_pData = nullptr;
        return temp;
    }
    // Resets the UniquePtr to manage a new raw pointer, deleting the old one if necessary
    void reset(T* ptr = nullptr) noexcept {
        delete m_pData;
        m_pData = ptr;
    }

    // Contextual boolean check (Mandatory for: if (sharedPtr) { ... })
    explicit operator bool() const noexcept { return m_pData != nullptr; }

    // C++20 and above Single Comparison Operator
    // This single function automatically enables:
    // ptr == nullptr, nullptr == ptr, ptr != nullptr, and nullptr != ptr!
    bool operator==(std::nullptr_t) const noexcept { return m_pData == nullptr; }
};
