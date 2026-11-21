# Assignment 1 - CO1: Metro Smart-Card Fare System
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 02: Use Tokens, Keywords, Identifiers and Constants Correctly

### 1. Five Kinds of Tokens in C++
- **Keywords**: Reserved words with fixed semantics (`constexpr`, `class`, `enum`, `bool`, `return`, `int`).
- **Identifiers**: Programmer-defined names (`BASE_PAISE`, `Zone`, `calculateFare`, `MIN_BALANCE_PAISE`). Follows camelCase/UPPER_SNAKE_CASE rules.
- **Constants (Literals)**: Fixed values (`1000`, `20`, `5000`, `true`).
- **Operators**: Symbols performing computations (`+`, `-`, `*`, `/`, `[]`, `==`, `&&`).
- **Punctuators (Separators)**: Syntax delimiters (`;`, `,`, `{`, `}`, `(`, `)`).

### 2. Comparison of #define vs const vs constexpr
- `#define`: Preprocessor text substitution without type checking or scope adherence. Prone to macro expansion side effects and impossible to debug.
- `const`: Variables whose values cannot be modified after initialization. May be evaluated at runtime.
- `constexpr`: Guaranteed compile-time evaluation where possible, strictly typed, scoped within namespaces/classes, zero runtime overhead. Essential for robust embedded/high-throughput fare engines.

### 3. enum vs enum class
- Traditional `enum` exports identifiers to the enclosing scope (polluting namespace) and implicitly converts to `int`, leading to accidental bugs (e.g., comparing `Zone::Inner == Color::Red`).
- `enum class` (scoped enumeration) is strongly typed and strictly scoped. Requires explicit scoping (`Zone::Inner`) and explicit casting (`static_cast<int>(z)`), eliminating accidental semantic errors.

### 4. Alternative Concept and Complexity Analysis
- Replacing `constexpr` constants with `#define` creates untyped macro substitutions. Time complexity remains O(1) compile-time and runtime, but type safety drops significantly.

### Output Log
```
--- Centralized Configuration Constants ---
Inner Fare (Off-peak): Rs 10
Outer Fare (Peak): Rs 36
Minimum Required Balance: Rs 50

```
