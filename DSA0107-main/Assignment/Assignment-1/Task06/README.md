# Assignment 1 - CO1: Metro Smart-Card Fare System
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 06: Design the Control Structures

### 1. Completed Code Implementation
The TODO placeholders in the assignment were completed:
- `TODO 1 (fare)`: Evaluates `Zone` using a switch block and adds 20% peak surcharge using pure integer arithmetic `base + (base * 20) / 100`.
- `TODO 2 (canTravel)`: Ensures `(balance - fare) >= MIN_BALANCE_PAISE`.

### 2. Execution and Output Validation
Expected Output from Assignment document:
```
Fare Rs 10.00  balance Rs 90
Fare Rs 36.00  balance Rs 54
Denied (low balance)  balance Rs 54
```
Actual Output obtained:
```
Fare Rs 10.00  balance Rs 90
Fare Rs 36.00  balance Rs 54
Denied (low balance)  balance Rs 54
```
Matches expected specification with 100% precision.

### 3. Control Structures Comparison
- **`switch` vs `if-else`**: The `switch` statement produces a jump table for O(1) branch dispatch on discrete enumerations.
- **Range-based for loop**: `for (const Trip& t : trips)` provides memory safety, eliminates bounds checking errors, and prevents accidental modifications.

### Output Log
```
Fare Rs 10.00  balance Rs 90
Fare Rs 36.00  balance Rs 54
Denied (low balance)  balance Rs 54

```
