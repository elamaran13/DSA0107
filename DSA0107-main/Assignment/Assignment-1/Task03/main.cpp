// Task 3: Choose Data Types and Check Type Compatibility
#include <iostream>
#include <climits>

int main() {
    std::cout << "--- Data Type Sizes and Ranges ---\n";
    std::cout << "sizeof(bool): " << sizeof(bool) << " byte\n";
    std::cout << "sizeof(char): " << sizeof(char) << " byte\n";
    std::cout << "sizeof(int): " << sizeof(int) << " bytes (Max: " << INT_MAX << ")\n";
    std::cout << "sizeof(long long): " << sizeof(long long) << " bytes (Max: " << LLONG_MAX << ")\n";
    std::cout << "sizeof(double): " << sizeof(double) << " bytes\n\n";

    // Daily collection overflow test
    // Metro with 3,000,000 journeys at Rs 36 (3600 paise)
    long long totalJourneys = 3000000;
    long long farePaise = 3600;
    long long networkTotalPaise = totalJourneys * farePaise; // 10,800,000,000 paise
    int intOverflowTotal = static_cast<int>(networkTotalPaise);

    std::cout << "Calculated Daily Total (long long paise): " << networkTotalPaise << " paise (Rs " << networkTotalPaise / 100 << ")\n";
    std::cout << "Calculated Daily Total (int paise): " << intOverflowTotal << " (Overflowed!)\n";

    return 0;
}
