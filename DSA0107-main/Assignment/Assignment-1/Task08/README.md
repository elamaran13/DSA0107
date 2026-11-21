# Assignment 1 - CO1: Metro Smart-Card Fare System
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 08: Read and Print Data Safely

### 1. Robust Console I/O & Stream State
- If a user inputs non-numeric characters (e.g., `"abc"`) when an integer/hour is expected:
  1. `std::cin` enters a fail state (`std::cin.fail() == true`).
  2. Future reading operations immediately fail and no values are consumed.
  3. Correct recovery protocol:
     ```cpp
     std::cin.clear(); // Clear the error flags
     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad line
     ```

### 2. I/O Manipulator Formatting
- Used `<iomanip>` manipulators:
  - `std::setw(2)`: Ensures two-digit representation for paise.
  - `std::setfill('0')`: Prepends leading zeroes (e.g., `5` paise printed as `05`).
  - `std::fixed` and `std::setprecision(2)`: Enforces exact two decimal digits for currency display.

### Output Log
```
--- Gate Terminal Simulation ---
Formatting Currency Example:
Fare: Rs 36.00
Formatted with fill: Rs 36.00

Input recovery pattern demonstration:
State checking: cin.fail() detects mismatched types (e.g., entering letters for numbers).
Recovery code: cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

```
