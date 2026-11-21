// Task 1: Object-Oriented Analysis & Modeling
#include <iostream>
#include <string>

enum class Zone { Inner = 1, Middle, Outer };

class SmartCard {
private:
    std::string cardId;
    long long balancePaise;
public:
    SmartCard(const std::string& id, long long initialBalance)
        : cardId(id), balancePaise(initialBalance) {}

    std::string getId() const { return cardId; }
    long long getBalance() const { return balancePaise; }

    bool canTravel(long long farePaise, long long minBalancePaise = 5000) const {
        return (balancePaise - farePaise) >= minBalancePaise;
    }

    bool deduct(long long farePaise, long long minBalancePaise = 5000) {
        if (canTravel(farePaise, minBalancePaise)) {
            balancePaise -= farePaise;
            return true;
        }
        return false;
    }

    void recharge(long long paise) {
        if (paise > 0) balancePaise += paise;
    }
};

int main() {
    SmartCard card("METRO1001", 10000); // Rs 100.00
    std::cout << "Card ID: " << card.getId() << "\n";
    std::cout << "Initial Balance: Rs " << (card.getBalance() / 100.0) << "\n";

    long long fare1 = 3600; // Rs 36.00
    if (card.deduct(fare1)) {
        std::cout << "Deducted Rs " << (fare1 / 100.0) << ". New Balance: Rs " << (card.getBalance() / 100.0) << "\n";
    }

    long long fare2 = 2000; // Rs 20.00 - should fail because 64 - 20 = 44 < 50
    if (!card.deduct(fare2)) {
        std::cout << "Denied: Minimum balance of Rs 50.00 required. Current Balance: Rs " << (card.getBalance() / 100.0) << "\n";
    }

    return 0;
}
