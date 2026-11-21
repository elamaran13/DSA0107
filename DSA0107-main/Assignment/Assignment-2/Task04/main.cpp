// Q4: Specifying a Class with an Array Inside It (Circular Transaction Buffer)
#include <iostream>
#include <iomanip>
#include <string>

class SavingsAccount {
private:
    std::string accountNumber;
    long long balancePaise;
    static const int MAX_HISTORY = 10;
    long long transactions[MAX_HISTORY];
    int count;
    int head; // Head pointer for circular buffer O(1) insertion

public:
    SavingsAccount(const std::string& accNo, long long initialBal)
        : accountNumber(accNo), balancePaise(initialBal), count(0), head(0) {}

    void deposit(long long amountPaise) {
        if (amountPaise <= 0) return;
        balancePaise += amountPaise;
        recordTransaction(amountPaise);
    }

    bool withdraw(long long amountPaise) {
        if (amountPaise <= 0 || balancePaise < amountPaise) return false;
        balancePaise -= amountPaise;
        recordTransaction(-amountPaise);
        return true;
    }

    void recordTransaction(long long amt) {
        transactions[head] = amt;
        head = (head + 1) % MAX_HISTORY;
        if (count < MAX_HISTORY) count++;
    }

    void printMiniStatement() const {
        std::cout << "=== Mini Statement for Account: " << accountNumber << " ===\n";
        std::cout << "Current Balance: Rs " << (balancePaise / 100.0) << "\n";
        std::cout << "Last Transactions (up to 10):\n";
        int start = (count < MAX_HISTORY) ? 0 : head;
        for (int i = 0; i < count; ++i) {
            int idx = (start + i) % MAX_HISTORY;
            long long tx = transactions[idx];
            std::cout << "  " << (i + 1) << ". " << (tx >= 0 ? "CR  Rs " : "DR  Rs ")
                      << std::abs(tx) / 100.0 << "\n";
        }
    }
};

int main() {
    SavingsAccount acc("SB-100234", 500000); // Rs 5,000.00
    acc.deposit(100000); // 1
    acc.withdraw(50000); // 2
    acc.deposit(20000);  // 3
    acc.withdraw(10000); // 4
    acc.deposit(15000);  // 5
    acc.withdraw(25000); // 6
    acc.deposit(30000);  // 7
    acc.withdraw(5000);  // 8
    acc.deposit(40000);  // 9
    acc.withdraw(15000); // 10
    acc.deposit(80000);  // 11 (causes eviction of oldest transaction)

    acc.printMiniStatement();
    return 0;
}
