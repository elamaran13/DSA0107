// Task 7: Procedural vs Object-Oriented Architecture
#include <iostream>
#include <string>

// --- Procedural Paradigm ---
namespace Procedural {
    bool canTravel(long long balance, long long fare, long long minBal) {
        return (balance - fare) >= minBal;
    }
    void deductFare(long long& balance, long long fare, long long minBal) {
        if (canTravel(balance, fare, minBal)) {
            balance -= fare;
        }
    }
}

// --- Object-Oriented Paradigm ---
namespace OOP {
    class SmartCard {
    private:
        std::string cardId;
        long long balancePaise;
        static constexpr long long MIN_BALANCE_PAISE = 5000;
    public:
        SmartCard(const std::string& id, long long initialBal)
            : cardId(id), balancePaise(initialBal) {}

        bool canTravel(long long fare) const {
            return (balancePaise - fare) >= MIN_BALANCE_PAISE;
        }

        bool deduct(long long fare) {
            if (!canTravel(fare)) return false;
            balancePaise -= fare;
            return true;
        }

        long long getBalance() const { return balancePaise; }
    };
}

int main() {
    std::cout << "--- Procedural vs OOP Demonstration ---\n";
    // Procedural vulnerability: direct variable access
    long long procBal = 10000;
    Procedural::deductFare(procBal, 3600, 5000);
    // Any outside code can directly corrupt procBal:
    procBal = -500; // Uncontrolled modification!
    std::cout << "Procedural exposed balance corrupted: " << procBal << "\n";

    // OOP encapsulation:
    OOP::SmartCard card("CARD99", 10000);
    card.deduct(3600);
    // card.balancePaise = -500; // COMPILATION ERROR: balance is private!
    std::cout << "OOP protected balance: Rs " << card.getBalance() / 100.0 << "\n";

    return 0;
}
