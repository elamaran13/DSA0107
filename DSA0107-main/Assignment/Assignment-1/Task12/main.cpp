// Task 12: Day-4 Design Challenge - Extended Metro System
#include <iostream>
#include <iomanip>
#include <string>

enum class Zone { Inner = 0, Middle = 1, Outer = 2, Airport = 3 };

class ExtendedFareEngine {
public:
    // Added 4th Zone: Airport = Rs 60 (6000 paise)
    static constexpr int BASE_PAISE[] = {1000, 2000, 3000, 6000};
    static constexpr int PEAK_SURCHARGE_PERCENT = 20;
    static constexpr int WEEKEND_DISCOUNT_PERCENT = 10;
    static constexpr long long MIN_BALANCE = 5000;

    static bool isPeak(int hour, bool isWeekend) {
        if (isWeekend) return false; // Peak surcharge does NOT apply on weekends
        return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    }

    static long long computeFare(Zone z, int hour, bool isWeekend, bool hasMonthlyPassForZone = false) {
        if (hasMonthlyPassForZone) {
            return 0; // Unlimited travel in subscribed pass zones
        }
        long long fare = BASE_PAISE[static_cast<int>(z)];
        if (isWeekend) {
            // 10% weekend discount does not combine with peak surcharge
            fare -= (fare * WEEKEND_DISCOUNT_PERCENT) / 100;
        } else if (isPeak(hour, isWeekend)) {
            fare += (fare * PEAK_SURCHARGE_PERCENT) / 100;
        }
        return fare;
    }
};

int main() {
    std::cout << "=== Day-4 Design Challenge: Extended Fare Engine ===\n";
    // 1. Airport Zone Off-peak
    long long f1 = ExtendedFareEngine::computeFare(Zone::Airport, 12, false);
    std::cout << "Airport Zone Weekday Off-Peak: Rs " << f1 / 100.0 << " (Expected Rs 60.00)\n";

    // 2. Airport Zone Weekend (10% discount -> Rs 54.00)
    long long f2 = ExtendedFareEngine::computeFare(Zone::Airport, 9, true);
    std::cout << "Airport Zone Weekend (9 AM): Rs " << f2 / 100.0 << " (Expected Rs 54.00, no peak)\n";

    // 3. Monthly pass holder in Inner zone
    long long f3 = ExtendedFareEngine::computeFare(Zone::Inner, 9, false, true);
    std::cout << "Monthly Pass Commuter (Inner Zone): Rs " << f3 / 100.0 << " (Free)\n";

    return 0;
}
