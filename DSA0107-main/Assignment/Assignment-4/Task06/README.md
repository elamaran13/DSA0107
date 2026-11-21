# Assignment 4 - CO4: Designing Reusable Class Hierarchies & Pointers
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 06: Vehicle Rental Fleet Design Challenge

### 1. Extensible Class Hierarchy Architecture
- Abstract base class `Vehicle` encapsulates common properties (`registrationNumber`, `model`, `baseHourlyRate`) with virtual destructor and polymorphic interface `calculateRentalCost(hours)`.
- Derived subclasses model real-world business constraints:
  - `Bicycle`: Fixed low hourly rate with zero fuel surcharge.
  - `TwoWheeler`: Incorporates fuel surcharge per hour.
  - `Car`: Incorporates seating capacity and 10% long-duration discount (> 10 hrs).
  - `ElectricCar`: Inherits from `Car`, adding battery telemetry and a 5% green tax rebate.

### 2. Execution Log
```
=== Vehicle Rental Fleet Hierarchy ===
Calculating rental cost for 12 hours across fleet:
[Bicycle] Reg: BK-01 | Model: Hero Sprint | Rate/hr: Rs 20.00 | Total Cost: Rs 240.00
[TwoWheeler] Reg: TN-09-AB-1234 | Model: Honda Activa | Rate/hr: Rs 60.00 | Total Cost: Rs 900.00
[Car] Reg: TN-07-CD-5678 | Model: Hyundai Creta | Rate/hr: Rs 150.00 | Total Cost: Rs 1620.00
[ElectricCar] Reg: TN-01-EV-9999 | Model: Tata Nexon EV | Rate/hr: Rs 180.00 | Total Cost: Rs 1846.80
```
Polymorphism dynamically resolves exact billing across diverse fleet types.

### Output Log
```
=== Vehicle Rental Fleet Hierarchy ===
Calculating rental cost for 12 hours across fleet:
[Bicycle] Reg: BK-01 | Model: Hero Sprint | Rate/hr: Rs 20 | Total Cost: Rs 240.00
[TwoWheeler] Reg: TN-09-AB-1234 | Model: Honda Activa | Rate/hr: Rs 60.00 | Total Cost: Rs 900.00
[Car] Reg: TN-07-CD-5678 | Model: Hyundai Creta | Rate/hr: Rs 150.00 | Total Cost: Rs 1620.00
[ElectricCar] Reg: TN-01-EV-9999 | Model: Tata Nexon EV | Rate/hr: Rs 180.00 | Total Cost: Rs 1846.80

```
