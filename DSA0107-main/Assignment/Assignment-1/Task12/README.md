# Assignment 1 - CO1: Metro Smart-Card Fare System
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 12: Re-evaluate and Adapt the Design (Day-4 Design Challenge)

### 1. Changed Requirements Analysis
- Added **Zone 4 (Airport)**: Fare = Rs 60 (6000 paise).
- Added **10% Weekend Discount**: Mutually exclusive with the 20% peak surcharge.
- Added **Monthly Pass**: Allows unlimited travel (fare = 0) in two designated zones.

### 2. Design Evaluation and Adaptations (RETAIN -> MODIFY -> REDESIGN)
- **RETAIN**:
  - `long long` paise financial representation for exact accounting.
  - Minimum balance invariant check of Rs 50.
- **MODIFY**:
  - `Zone` enum: Extended with `Zone::Airport`.
  - `BASE_PAISE` table: Updated to `{1000, 2000, 3000, 6000}`.
  - Surcharge/Discount logic: Checked with mutual exclusion (`isWeekend` overrides peak surcharge).
- **REDESIGN**:
  - Added pass entitlement check (`hasMonthlyPassForZone`) returning zero-charge deductions.

### 3. Verification Log
```
=== Day-4 Design Challenge: Extended Fare Engine ===
Airport Zone Weekday Off-Peak: Rs 60 (Expected Rs 60.00)
Airport Zone Weekend (9 AM): Rs 54 (Expected Rs 54.00, no peak)
Monthly Pass Commuter (Inner Zone): Rs 0 (Free)
```

### Output Log
```
=== Day-4 Design Challenge: Extended Fare Engine ===
Airport Zone Weekday Off-Peak: Rs 60 (Expected Rs 60.00)
Airport Zone Weekend (9 AM): Rs 54 (Expected Rs 54.00, no peak)
Monthly Pass Commuter (Inner Zone): Rs 0 (Free)

```
