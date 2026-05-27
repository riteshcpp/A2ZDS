#include <SmartPointer.h>
#include <cassert>

// =========================================================================
// TEST HIERARCHY SETUP
// =========================================================================
class Instrument {
public:
    virtual void play() { std::cout << "     [Instrument] Emitting generic sound...\n"; }
    virtual ~Instrument() { std::cout << "     [Instrument] Cleaned from heap.\n"; }
};

class Guitar : public Instrument {
public:
    void play() override { std::cout << "     [Guitar] Strumming clean chords!\n"; }
    ~Guitar() override { std::cout << "     [Guitar] Cleaned from heap.\n"; }
};

// =========================================================================
// CLIENT SUITE: MAIN VERIFICATION LOOP
// =========================================================================
int main() {
    std::cout << "==================================================\n";
    std::cout << "📢 RUNNING POSITIVE SMART POINTER TESTS\n";
    std::cout << "==================================================\n";

    std::cout << "\n[POS] 1. SharedPtr Core & Operators\n";
    {
        SharedPtr<Guitar> sp1(new Guitar());
        assert(sp1.use_count() == 1);
        
        if (sp1) { sp1->play(); } // Triggers operator bool and operator->
        (*sp1).play();            // Triggers operator*
    } // Verifies basic heap automatic cleanup engine

    std::cout << "\n[POS] 2. SharedPtr Upcasting Conversions\n";
    {
        SharedPtr<Guitar> myGuitar(new Guitar());
        SharedPtr<Instrument> generalInst = myGuitar; // Triggers Conversion Ctor
        assert(myGuitar.use_count() == 2);
        
        SharedPtr<Instrument> assignmentSlot;
        assignmentSlot = myGuitar;                    // Triggers Conversion Assignment
        assert(myGuitar.use_count() == 3);
        assignmentSlot->play();                       // Ensures accurate polymorphic binding
    }

    std::cout << "\n[POS] 3. SharedPtr Move Semantics\n";
    {
        SharedPtr<Guitar> spMove1(new Guitar());
        SharedPtr<Guitar> spMove2 = std::move(spMove1); // Triggers Same-Type Move Constructor
        assert(spMove1.get() == nullptr);
        assert(spMove2.use_count() == 1);

        SharedPtr<Instrument> baseMoveSlot;
        baseMoveSlot = std::move(spMove2);              // Triggers Template Conversion Move Assignment
        assert(spMove2.get() == nullptr);
    }

    std::cout << "\n[POS] 4. WeakPtr Tracking and Promotion Locking\n";
    {
        WeakPtr<Instrument> wp;
        {
            SharedPtr<Guitar> sp(new Guitar());
            wp = sp; // Triggers Conversion Assignment from SharedPtr to WeakPtr
            assert(sp.use_count() == 1);
            assert(!wp.expired());

            SharedPtr<Instrument> locked = wp.lock(); // Promotes observer back to temporary owner
            assert(sp.use_count() == 2);
            locked->play();
        } // Active owner pointers leave scope here
        assert(wp.expired()); // Confirms structural tracking block drops correctly
    }

    std::cout << "\n[POS] 5. UniquePtr Ownership Handling\n";
    {
        UniquePtr<Guitar> up1(new Guitar());
        if (up1) { up1->play(); }
        
        UniquePtr<Instrument> upBase = std::move(up1); // Triggers Conversion Move Ctor
        assert(up1.get() == nullptr);
        upBase->play();

        Instrument* raw = upBase.release(); // Relinquishes tracking obligations
        assert(upBase.get() == nullptr);
        delete raw;
    }

    std::cout << "\n==================================================\n";
    std::cout << "⚠️ RUNNING NEGATIVE TESTING SCOPES (EDGE CASES)\n";
    std::cout << "==================================================\n";

    std::cout << "\n[NEG] 1. Empty / Default States\n";
    {
        SharedPtr<Guitar> emptyShared;
        UniquePtr<Guitar> emptyUnique;
        WeakPtr<Guitar> emptyWeak;

        assert(emptyShared.get() == nullptr);
        assert(emptyShared.use_count() == 0);
        assert(emptyUnique.get() == nullptr);
        assert(emptyWeak.expired());
        
        // C++20 Symmetric Comparison check validations without written boilerplate
        assert(emptyShared == nullptr);
        assert(nullptr == emptyShared);
        assert(emptyUnique == nullptr);
        assert(nullptr == emptyUnique);
        
        if (emptyShared) { assert(false); } // Ensuring empty evaluation context passes cleanly
    }

    std::cout << "\n[NEG] 2. Expired WeakPtr Interaction\n";
    {
        WeakPtr<Guitar> fragileObserver;
        {
            SharedPtr<Guitar> transitoryAsset(new Guitar());
            fragileObserver = transitoryAsset;
        } // transitoryAsset leaves scope and calls destructor
        
        assert(fragileObserver.expired());
        SharedPtr<Guitar> failedLock = fragileObserver.lock();
        assert(failedLock.get() == nullptr); // Lock promotion fails cleanly on dead pointers
        std::cout << "     Safe outcome: Lock promotion bypassed dead tracking target.\n";
    }

    std::cout << "\n[NEG] 3. Self-Assignment Mitigation Loops\n";
    {
        SharedPtr<Guitar> loopPtr(new Guitar());
        loopPtr = loopPtr; // Verifies single-type identity guard (this != &src)
        assert(loopPtr.use_count() == 1);

        SharedPtr<Instrument> crossLoopPtr = loopPtr;
        crossLoopPtr = loopPtr; // Verifies cross-type identity template guard (m_pCb != src.m_pCb)
        assert(loopPtr.use_count() == 2);
    }

    std::cout << "\n🌟 ALL REPLICATED SMART POINTER HARNESS TESTS COMPLETED SUCCESSFULLY! 🌟\n";
    return 0;
}
