// Q7: Design a Complex-Number Class from First Principles (AC Circuit Impedance Calculator)
#include <iostream>
#include <cmath>
#include <iomanip>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Addition (Series Impedance: Z_total = Z1 + Z2)
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Multiplication: Z1 * Z2
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    // Division (Parallel Impedance: Z_eq = (Z1 * Z2) / (Z1 + Z2))
    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denom,
                       (imag * other.real - real * other.imag) / denom);
    }

    double magnitude() const {
        return std::sqrt(real * real + imag * imag);
    }

    double phaseDegrees() const {
        return std::atan2(imag, real) * 180.0 / 3.14159265358979323846;
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << std::fixed << std::setprecision(2) << c.real 
           << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << "j";
        return os;
    }
};

int main() {
    std::cout << "=== AC Circuit Impedance Calculator ===\n";
    Complex z1(10.0, 5.0);  // Resistor + Inductor: 10 + 5j ohms
    Complex z2(15.0, -8.0); // Resistor + Capacitor: 15 - 8j ohms

    Complex zSeries = z1 + z2;
    Complex zParallel = (z1 * z2) / (z1 + z2);

    std::cout << "Z1 (Branch 1): " << z1 << " (Magnitude: " << z1.magnitude() << " ohms)\n";
    std::cout << "Z2 (Branch 2): " << z2 << " (Magnitude: " << z2.magnitude() << " ohms)\n";
    std::cout << "Z_Series     : " << zSeries << " (Magnitude: " << zSeries.magnitude() << " ohms)\n";
    std::cout << "Z_Parallel   : " << zParallel << " (Magnitude: " << zParallel.magnitude() << " ohms)\n";

    return 0;
}
