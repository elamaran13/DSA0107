// Q1: Call by Value, by Reference, and by Pointer (Complete the Code & Comparison)
#include <iostream>

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100; // Modifies only local copy
}

void applyConcession(long long& fee, int percent) {
    // TODO 1: Reduce the caller's fee by percent using integer arithmetic (call by reference)
    fee -= (fee * percent) / 100;
}

void applyByPointer(long long* fee, int percent) {
    if (fee != nullptr) {
        *fee -= (*fee * percent) / 100;
    }
}

int main() {
    long long hostelFee = 45000;
    applyByValue(hostelFee, 10);
    std::cout << "after call by value\t: " << hostelFee << '\n';

    applyConcession(hostelFee, 10);
    std::cout << "after call by reference: " << hostelFee << '\n';

    long long hostelFeePtr = 45000;
    applyByPointer(&hostelFeePtr, 10);
    std::cout << "after call by pointer  : " << hostelFeePtr << '\n';

    return 0;
}
