// Q4: Overloading Arithmetic and Stream Operators (Complete the Code)
#include <iomanip>
#include <iostream>

class Money {
    long long paise;
public:
    Money(long long rupees = 0, int p = 0) : paise(rupees * 100 + p) {}

    // TODO 1: Overload + as a member function that returns a new Money object
    Money operator+(const Money& other) const {
        Money result;
        result.paise = this->paise + other.paise;
        return result;
    }

    // TODO 2: Overload == as a member, and << as a friend that prints "Rs 200.00"
    bool operator==(const Money& other) const {
        return this->paise == other.paise;
    }

    friend std::ostream& operator<<(std::ostream& os, const Money& m) {
        long long r = m.paise / 100;
        int p = std::abs(static_cast<int>(m.paise % 100));
        os << "Rs " << r << '.' << std::setw(2) << std::setfill('0') << p << std::setfill(' ');
        return os;
    }
};

int main() {
    Money a(120, 75), b(79, 25);
    Money c = a + b;
    std::cout << c << '\n' << std::boolalpha << (c == Money(200)) << '\n';
    return 0;
}
