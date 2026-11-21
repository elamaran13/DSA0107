# Assignment 1 - CO1: Metro Smart-Card Fare System
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 03: Choose Data Types and Check Type Compatibility

### 1. Data Type Selection Matrix
- **Fares & Balances**: `long long` (integer paise). Prevents IEEE 754 floating point precision decay.
- **Peak Hour Flag**: `bool` (1 byte, `true`/`false`).
- **Zone Codes**: `enum class Zone : int` (strongly typed).
- **Hours & Counts**: `int` (standard machine register width).

### 2. Why Integer Paise vs Double Rupees
Floating-point numbers (`double` and `float`) represent decimal values using binary fractions. Decimal values like `0.10` or `0.20` cannot be stored with exact precision in IEEE 754 format:
- `0.10 + 0.20 != 0.30` (evaluates to `0.30000000000000004`).
- Over millions of transactions, rounding discrepancies accumulate into significant financial audit discrepancies.
- Integer paise guarantees exact arithmetic with zero truncation error.

### 3. Range Verification and Overflow
- `INT_MAX` on 32/64-bit systems is 2,147,483,647 (approx Rs 2.14 Crores in paise).
- A daily collection across 3,000,000 journeys at Rs 36 averages 10,800,000,000 paise (Rs 10.8 Crores), which immediately overflows a 32-bit signed `int`.
- Hence, `long long` (up to 9.22 × 10^18 paise) is mandatory for financial counters.

### Output Log
```
--- Data Type Sizes and Ranges ---
sizeof(bool): 1 byte
sizeof(char): 1 byte
sizeof(int): 4 bytes (Max: 2147483647)
sizeof(long long): 8 bytes (Max: 9223372036854775807)
sizeof(double): 8 bytes

Calculated Daily Total (long long paise): 10800000000 paise (Rs 108000000)
Calculated Daily Total (int paise): -2084901888 (Overflowed!)

```
