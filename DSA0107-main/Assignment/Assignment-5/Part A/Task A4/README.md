# Assignment 5 - CO5: Polymorphism and Exception Handling
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task A4: Design the Exception Strategy

### 1. Failure Categories & Custom Exceptions
- **`NegativeAmountException`**: Triggers when negative units, prices, or days are passed.
- **`CoverExceededException`**: Triggers when reimbursement requested exceeds policy limits.
- **`InvalidPatientException`**: Triggers on missing mandatory demographic records.

### 2. Standard Exception Inheritance
All custom exceptions inherit from `std::runtime_error` (and ultimately `std::exception`). This guarantees callers can catch high-level exceptions polymorphically (`catch (const std::exception& e)`).

### Output Log
```
=== Hospital Exception Hierarchy Defined ===
Base: HospitalBillingException -> std::runtime_error
Derived: NegativeAmountException, CoverExceededException, InvalidPatientException

```
