# Assignment 1 - CO1: Metro Smart-Card Fare System
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 05: Write Correct Expressions with the Right Precedence

### 1. Predict the Output Analysis
- `x + y * 2`: `*` has higher precedence than `+` -> `5 + (3 * 2) = 11`. `(x + y) * 2 = 16`.
- `z = x++ + ++y`: `x++` evaluates to `5` (increments `x` to `6` after fetch). `++y` increments `y` from `3` to `4` before fetch. `z = 5 + 4 = 9`. Values: `x = 6, y = 4`.
- `(x > y ? x : y)`: `6 > 4 ? 6 : 4` -> `6`.
- `x % 4 * 2`: Left-to-right associativity -> `(6 % 4) * 2 = 2 * 2 = 4`.
- `10 / 3` is `3`, `10 % 3` is `1`. In C++11 and later, integer division truncates toward zero: `-10 / 3` is `-3`, `-10 % 3` is `-1`.
- Loop `i` takes values: `0, 3, 6, 9` -> sum `k = 0 + 3 + 6 + 9 = 18`.

### 2. Actual Program Output
```
11 16
9 6 4
6 4
3 1 -3 -1
18
```

### 3. Logic & Precedence Rules
- Peak hour expression: `(hour >= 8 && hour < 10) || (hour >= 17 && hour < 20)`
- Parentheses prevent precedence ambiguity between logical AND (`&&`) and logical OR (`||`).
- Undefined behavior warning: Expressions like `i = i++` violate sequence point rules in pre-C++17 and should never be used.

### Output Log
```
11 16
9 6 4
6 4
3 1 -3 -1
18

```
