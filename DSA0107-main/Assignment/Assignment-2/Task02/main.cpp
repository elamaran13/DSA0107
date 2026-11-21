// Q2: Return by Reference and Its Dangers
#include <iostream>

int& getHighestMark(int marks[], int size) {
    int maxIdx = 0;
    for (int i = 1; i < size; ++i) {
        if (marks[i] > marks[maxIdx]) {
            maxIdx = i;
        }
    }
    return marks[maxIdx]; // Safe: array outlives function scope
}

// DANGEROUS FUNCTION: returning reference to local variable
// int& dangerousLocal() { int temp = 100; return temp; } // Triggers compiler warning: reference to local variable returned

int main() {
    int marks[] = {78, 85, 92, 64, 88};
    int n = 5;

    std::cout << "Original marks: ";
    for (int i = 0; i < n; ++i) std::cout << marks[i] << " ";
    std::cout << "\n";

    // Modifying through reference returned on LHS
    getHighestMark(marks, n) = 99; // Changes 92 to 99!

    std::cout << "After getHighestMark(marks, n) = 99: ";
    for (int i = 0; i < n; ++i) std::cout << marks[i] << " ";
    std::cout << "\n";

    return 0;
}
