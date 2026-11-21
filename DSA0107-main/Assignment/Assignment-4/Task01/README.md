# Assignment 4 - CO4: Designing Reusable Class Hierarchies & Pointers
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 01: Class Design Review (Diagnose and Repair Duplicated Classes)

### 1. Diagnosis of Original Design Defects (Task 1.1)
The original three separate classes (`Professor`, `LabAssistant`, `GuestFaculty`) exhibited severe architectural flaws:
1. **Redundancy & Code Duplication**: `name`, `id`, `basic`, and `da` (and the formula `basic + basic * 0.42`) were duplicated verbatim across multiple classes.
2. **Inconsistent Naming**: In `GuestFaculty`, identifier names randomly shifted (`nm`, `code`) instead of `name` and `id`.
3. **Lack of Polymorphic Extensibility**: No shared base class (`Employee*`), making it impossible to store all university employees in a unified collection or iterate over payroll uniformly.

### 2. Repaired Class Hierarchy (Task 1.2 & 1.3)
- Constructed an abstract base `Employee` declaring common identifiers and a pure virtual `calculatePay()`.
- Derived `SalariedEmployee` factoring out common basic pay and DA calculations.
- Derived `Professor` (adds research allowance) and `LabAssistant` from `SalariedEmployee`.
- Derived `GuestFaculty` directly from `Employee` (hourly compensation model).

### Output Log
```
=== Repaired College Payroll Hierarchy ===
ID: 101 | Name: Dr. Raman | Pay: Rs 128600
ID: 202 | Name: Kannan | Pay: Rs 49700
ID: 303 | Name: Prof. Smith | Pay: Rs 48000

```
