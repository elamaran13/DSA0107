# Assignment 5 - CO5: Polymorphism and Exception Handling
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task A1: Design the Polymorphic Bill Hierarchy

### 1. Common Interface Specification (A1.1)
The abstract base `Bill` guarantees three fundamental operations for all healthcare billing:
- `virtual double total() const = 0;`: Calculates total charges specific to billing category.
- `virtual std::string type() const = 0;`: Identifies the bill classification (OP, IP, DayCare).
- `virtual void print() const;`: Uniform logging of patient name, category, and total amount.

### 2. Subclass Hierarchy (A1.2)
- **`OutPatientBill`**: Models consultation and diagnostic laboratory tests. Total = `consultation + lab`.
- **`InPatientBill`**: Models hospital admissions. Total = `(days * roomRent) + surgery`.
- **`EmergencyBill`**: Models triage and ICU intervention.

### Output Log
```
OP [Ravi] Total: Rs 1700
IP [Meena] Total: Rs 47500
Grand Total: Rs 49200

```
