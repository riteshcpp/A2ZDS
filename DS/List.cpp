#include <iostream>

template<typename T>
class List
{
private:
    struct node
    {
        T data;
        node* next;
        node(T data) : data(data), next(nullptr) {}
    };
    node* m_pStart = { nullptr };

public:
    List() {
        std::cout << "ctor" << std::endl;
    }
    void release(node* p) {
        std::cout << "release" << std::endl;
        while (p) {
            node* q = p;
            p = p->next;
            delete q; q = nullptr;
        }
    }
    ~List() {
        std::cout << "dtor" << std::endl;
        release(m_pStart);
    }
    List(const List& src) {
        std::cout << "copy ctor" << std::endl;

        if (src.m_pStart == nullptr)
            return;

        node* temp = src.m_pStart;
        node* start = nullptr;

        // Initialise first node
        m_pStart = new node(temp->data);
        start = m_pStart;
        temp = temp->next;

        // initialise other node
        while (temp) {
            start->next = new node(temp->data);
            start = start->next;
            temp = temp->next;
        }
    }
    List(List&& src) noexcept : m_pStart{ std::exchange(src.m_pStart, nullptr) } {
        std::cout << "Move ctor" << std::endl;
    }
    List& operator = (const List& src) {
        std::cout << "copy assignment" << std::endl;
        if (src.m_pStart == nullptr)
            return *this;

        if (this != &src) {
            node* currStart = m_pStart;
            try {
                node* temp = src.m_pStart;
                node* start = nullptr;
                // Initialise first node
                m_pStart = new node(temp->data);
                start = m_pStart;
                temp = temp->next;

                while (temp) {
                    start->next = new node(temp->data);
                    start = start->next;
                    temp = temp->next;
                }
            }
            catch (const std::bad_alloc& e) {
                m_pStart = currStart;
                return *this;
            }
            release(currStart);
        }
        return *this;
    }
    List& operator = (List&& src) noexcept {
        std::cout << "move assignment" << std::endl;
        if (this != &src) {
            release(m_pStart);
            m_pStart = src.m_pStart;
            src.m_pStart = nullptr;
        }
        return *this;
    }
    void insert(T data) {
        std::cout << "insert" << std::endl;
        if (m_pStart == nullptr) {
            m_pStart = new node(data);
        }
        else {
            node* p = m_pStart;
            while (p && p->next) {
                p = p->next;
            }
            p->next = new node(data);
        }
    }
    void deleteN(int data) {
        std::cout << "delete" << std::endl;
        node* p = m_pStart;
        if (p->data == data) {
            m_pStart = m_pStart->next;
            delete p; p = nullptr;
        }
        else {
            while (p->next) {
                if (p->next->data == data) {
                    node* q = p->next;
                    p->next = p->next->next;
                    delete q; q = nullptr;
                }
                p = p->next;
            }
        }
    }
    void reverse() {
        node* curr = m_pStart;
        node* prev = nullptr;
        node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        m_pStart = prev;
    }
};
int main() {
    std::cout << "=== Testing List<int> ===" << std::endl;
    
    // Test default constructor
    List<int> list1;

    // Test insert
    list1.insert(10);
    list1.insert(20);
    list1.insert(30);
    std::cout << "Inserted 10, 20, 30" << std::endl;

    // Test copy constructor
    List<int> list2 = list1;
    std::cout << "Copy constructor called" << std::endl;

    // Test move constructor
    List<int> list3 = std::move(list1);
    std::cout << "Move constructor called" << std::endl;

    // Test copy assignment
    List<int> list4;
    list4.insert(5);
    list4 = list2;
    std::cout << "Copy assignment called" << std::endl;

    // Test move assignment
    List<int> list5;
    list5 = std::move(list3);
    std::cout << "Move assignment called" << std::endl;

    // Test delete
    list2.deleteN(20);
    std::cout << "Deleted 20" << std::endl;

    // Test reverse
    list4.reverse();
    std::cout << "Reversed list4" << std::endl;

    std::cout << "\n=== Testing List<std::string> ===" << std::endl;
    
    // Test with string
    List<std::string> strList1;
    strList1.insert("Apple");
    strList1.insert("Banana");
    strList1.insert("Cherry");
    std::cout << "Inserted Apple, Banana, Cherry" << std::endl;

    // Copy constructor for strings
    List<std::string> strList2 = strList1;
    std::cout << "Copy constructor called for strings" << std::endl;

    // Move constructor for strings
    List<std::string> strList3 = std::move(strList1);
    std::cout << "Move constructor called for strings" << std::endl;

    // Copy assignment for strings
    List<std::string> strList4;
    strList4.insert("Date");
    strList4 = strList2;
    std::cout << "Copy assignment called for strings" << std::endl;

    // Move assignment for strings
    List<std::string> strList5;
    strList5 = std::move(strList3);
    std::cout << "Move assignment called for strings" << std::endl;

    // Delete from string list
    strList2.deleteN("Banana");
    std::cout << "Deleted Banana" << std::endl;

    // Reverse string list
    strList4.reverse();
    std::cout << "Reversed strList4" << std::endl;

    std::cout << "\nProgram ending, destructors will be called" << std::endl;
    return 0;
}