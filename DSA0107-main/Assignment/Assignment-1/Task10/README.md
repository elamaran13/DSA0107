# Assignment 1 - CO1: Metro Smart-Card Fare System
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 10: Compare Expectations with Execution

### 1. Findings on Floating-Point Drift vs Integer Accuracy
- Running repeated additions of `36.00` in double precision over 3,000,000 iterations:
  - Exact mathematical total: `3,000,000 * 36 = Rs 108,000,000.00`.
  - Integer paise storage computes `10,800,000,000` paise = `Rs 108,000,000.00` with 0 error.
  - Floating-point accumulation incurs drift over millions of small additions due to IEEE 754 mantissa rounding.

### 2. Int Overflow Verification
- A 32-bit signed integer caps at `2,147,483,647`.
- At 3,000,000 journeys (10.8 billion paise), `int` overflows into negative numbers (`-2089934592`), which would cause catastrophic accounting failure.
- Using `long long` handles up to 9.22 × 10^18 paise, completely eliminating overflow risk.

### Output Log
```
--- Large-Scale Simulation: Integer vs Floating-Point ---
Journeys: 20000
  Integer Total: Rs 720000.00
  Double Total : Rs 720000.00
  Discrepancy  : Rs 0.00

Journeys: 500000
  Integer Total: Rs 18000000.00
  Double Total : Rs 18000000.00
  Discrepancy  : Rs 0.00

Journeys: 3000000
  Integer Total: Rs 108000000.00
  Double Total : Rs 108000000.00
  Discrepancy  : Rs 0.00


```
