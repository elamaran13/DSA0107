// Q3: Default Arguments and Function Overloading
#include <iostream>
#include <string>

struct Parcel {
    double weightKg;
    std::string destination;
};

// Disambiguated function overloading with default arguments
// Overload 1: Weight in grams (int)
double calculateCharge(int grams, bool express = false, bool insurance = false) {
    double base = (grams / 500.0) * 50.0;
    if (express) base += 100.0;
    if (insurance) base += 50.0;
    return base;
}

// Overload 2: Weight in kg (double)
double calculateCharge(double kg, bool express = false, bool insurance = false) {
    double base = kg * 100.0;
    if (express) base += 100.0;
    if (insurance) base += 50.0;
    return base;
}

// Overload 3: Parcel struct
double calculateCharge(const Parcel& p, bool express = false, bool insurance = false) {
    return calculateCharge(p.weightKg, express, insurance);
}

int main() {
    std::cout << "Charge for 1500g (standard): Rs " << calculateCharge(1500) << "\n";
    std::cout << "Charge for 2.5kg (express, insured): Rs " << calculateCharge(2.5, true, true) << "\n";
    Parcel p{3.0, "Chennai"};
    std::cout << "Charge for Parcel (3.0kg, express): Rs " << calculateCharge(p, true) << "\n";
    return 0;
}
