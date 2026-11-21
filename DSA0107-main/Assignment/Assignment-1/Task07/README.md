# Assignment 1 - CO1: Metro Smart-Card Fare System
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 07: From Procedural to Object-Oriented

### 1. Procedural vs OOP Architecture
- **Procedural Implementation**: Functions and data are decoupled. The balance is an unprotected integer passed by reference. Any rogue module can set balance to negative values or bypass checks.
- **Object-Oriented Implementation**: The `SmartCard` class bundles state (`balancePaise`) and operations (`deduct()`, `canTravel()`) together. `balancePaise` is strictly `private`, ensuring internal invariants cannot be violated externally.

### 2. Maintenance and Extensibility
When the minimum balance requirement changes (e.g. from Rs 50 to Rs 60), in OOP it is updated in a single encapsulated constant (`MIN_BALANCE_PAISE`). In procedural code, every call site passing minimum balance arguments across large codebases must be audited and updated.

### Output Log
```
--- Procedural vs OOP Demonstration ---
Procedural exposed balance corrupted: -500
OOP protected balance: Rs 64

```
