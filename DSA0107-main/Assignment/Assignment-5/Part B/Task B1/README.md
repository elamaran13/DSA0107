# Assignment 5 - CO5: Polymorphism and Exception Handling
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task B1: Implement and Validate the Polymorphic Billing System

### 1. Implementation of Completed Code
- `TODO 1 (Bill)`: Declared pure virtual `virtual double total() const = 0;` and default virtual `virtual std::string type() const { return "Bill"; }`.
- `TODO 2 (OutPatient)`: Overrode `total()` as `consultation + tests` (500 + 1200 = 1700), and `type()` as `"OP"`.
- `TODO 3 (InPatient)`: Overrode `total()` as `(days * perDay) + surgery` (3 * 2500 + 40000 = 47500), and `type()` as `"IP"`.

### 2. Output Verification
Expected Output:
```
OP Ravi: 1700
IP Meena: 47500
Total 49200
```
Actual Output:
```
OP Ravi: 1700
IP Meena: 47500
Total 49200
```
Matches expected specification with 100% precision.

### Output Log
```
OP Ravi: 1700
IP Meena: 47500
Total 49200

```
