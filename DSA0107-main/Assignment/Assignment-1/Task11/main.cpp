// Task 11: Final Production Recommendation Architecture
#include <iostream>
#include <string>

class MetroSystemConfig {
public:
    static constexpr long long MIN_BALANCE_PAISE = 5000;
    static constexpr int PEAK_SURCHARGE_PERCENT = 20;
    static constexpr int BASE_PAISE[] = {1000, 2000, 3000};
};

int main() {
    std::cout << "=== Final Production Design Summary ===\n";
    std::cout << "Architecture: Strongly-typed OOP with static constexpr configuration.\n";
    std::cout << "Financial Storage: 64-bit integer paise (long long).\n";
    std::cout << "Safety Invariant: Hard minimum balance of Rs " << MetroSystemConfig::MIN_BALANCE_PAISE / 100.0 << "\n";
    return 0;
}
