// Part A - Task A4: Design the Exception Strategy
#include <iostream>
#include <stdexcept>
#include <string>

// Custom domain exception hierarchy
class HospitalBillingException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class NegativeAmountException : public HospitalBillingException {
public:
    NegativeAmountException() : HospitalBillingException("Validation Error: Negative charge encountered.") {}
};

class CoverExceededException : public HospitalBillingException {
public:
    CoverExceededException() : HospitalBillingException("Claim Error: Total billed exceeds maximum policy cover.") {}
};

class InvalidPatientException : public HospitalBillingException {
public:
    InvalidPatientException() : HospitalBillingException("Data Error: Patient identification missing or invalid.") {}
};

int main() {
    std::cout << "=== Hospital Exception Hierarchy Defined ===\n";
    std::cout << "Base: HospitalBillingException -> std::runtime_error\n";
    std::cout << "Derived: NegativeAmountException, CoverExceededException, InvalidPatientException\n";
    return 0;
}
