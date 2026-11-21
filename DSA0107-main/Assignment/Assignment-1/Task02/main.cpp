// Task 2: Tokens, Keywords, Identifiers and Constants Correctly
#include <iostream>

enum class Zone { Inner = 0, Middle = 1, Outer = 2 };

// Centralized constexpr constants
constexpr int BASE_PAISE[] = {1000, 2000, 3000}; // Rs 10, Rs 20, Rs 30
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;     // Rs 50.00
constexpr int PEAK_START_MORNING = 8;
constexpr int PEAK_END_MORNING = 10;
constexpr int PEAK_START_EVENING = 17;
constexpr int PEAK_END_EVENING = 20;

constexpr bool isPeakHour(int hour) {
    return (hour >= PEAK_START_MORNING && hour < PEAK_END_MORNING) ||
           (hour >= PEAK_START_EVENING && hour < PEAK_END_EVENING);
}

constexpr long long calculateFare(Zone z, bool peak) {
    long long base = BASE_PAISE[static_cast<int>(z)];
    if (peak) {
        base += (base * PEAK_SURCHARGE_PERCENT) / 100;
    }
    return base;
}

int main() {
    std::cout << "--- Centralized Configuration Constants ---\n";
    std::cout << "Inner Fare (Off-peak): Rs " << calculateFare(Zone::Inner, false) / 100.0 << "\n";
    std::cout << "Outer Fare (Peak): Rs " << calculateFare(Zone::Outer, true) / 100.0 << "\n";
    std::cout << "Minimum Required Balance: Rs " << MIN_BALANCE_PAISE / 100.0 << "\n";
    return 0;
}
