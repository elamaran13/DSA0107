# Assignment 5 - CO5: Polymorphism and Exception Handling
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task B4: Final Engineering Decision

### 1. Architectural Justification for Polymorphism
In large-scale enterprise hospital management systems (15 hospitals, continuous expansion):
- **Extensibility**: Adding new bill categories (e.g. `DayCareBill`, `RoboticSurgeryBill`) or new insurance payers is achieved purely by subclassing without recompiling or altering existing stable production classes.
- **Maintainability**: The minuscule vtable overhead (a few nanoseconds per call) is overwhelmingly outweighed by type safety, lack of spaghetti code, and complete elimination of centralized monolithic switch blocks.

### Output Log
```
=== Hospital Billing Extensibility Demonstration ===
OP Bill: Rs 1700
DayCare Bill: Rs 11700

```
