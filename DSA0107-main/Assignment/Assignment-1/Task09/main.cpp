// Task 9: Comprehensive Fare Engine Implementation and Test Suite
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

enum class Zone { Inner = 0, Middle = 1, Outer = 2 };

class FareEngine {
public:
    static constexpr int BASE_PAISE[] = {1000, 2000, 3000};
    static constexpr int PEAK_PERCENT = 20;
    static constexpr long long MIN_BALANCE = 5000;

    static bool isPeak(int hour) {
        return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    }

    static long long computeFare(Zone z, int hour) {
        long long fare = BASE_PAISE[static_cast<int>(z)];
        if (isPeak(hour)) {
            fare += (fare * PEAK_PERCENT) / 100;
        }
        return fare;
    }
};

struct TestCase {
    std::string description;
    Zone zone;
    int hour;
    long long initialBalance;
    bool expectedAllowed;
    long long expectedFare;
};

int main() {
    std::cout << "=== Test Suite: Metro Fare Logic Validation ===\n";
    std::vector<TestCase> tests = {
        {"Normal Inner Off-Peak (12:00)", Zone::Inner, 12, 10000, true, 1000},
        {"Peak Inner Boundary 8:00 AM", Zone::Inner, 8, 10000, true, 1200},
        {"Off-Peak Boundary 10:00 AM", Zone::Inner, 10, 10000, true, 1000},
        {"Peak Evening Boundary 17:00", Zone::Outer, 17, 10000, true, 3600},
        {"Exact Min Balance Remaining", Zone::Inner, 14, 6000, true, 1000}, // 6000 - 1000 = 5000 (Allowed)
        {"Insufficient Balance by 1 Paisa", Zone::Inner, 14, 5999, false, 1000} // 5999 - 1000 = 4999 < 5000 (Denied)
    };

    int passed = 0;
    for (const auto& t : tests) {
        long long f = FareEngine::computeFare(t.zone, t.hour);
        bool allowed = (t.initialBalance - f) >= FareEngine::MIN_BALANCE;
        bool pass = (allowed == t.expectedAllowed && f == t.expectedFare);
        if (pass) passed++;

        std::cout << "[" << (pass ? "PASS" : "FAIL") << "] " << t.description 
                  << " | Fare: Rs " << f / 100.0 
                  << " | Allowed: " << (allowed ? "YES" : "NO") << "\n";
    }

    std::cout << "\nTest Suite Result: " << passed << "/" << tests.size() << " Passed.\n";
    return 0;
}
