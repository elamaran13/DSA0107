# Assignment 1 - CO1: Metro Smart-Card Fare System
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 11: Recommend and Defend the Final Design

### 1. Architectural Recommendations
1. **Financial Primitives**: All monetary values MUST be stored as `long long` paise.
2. **Type Safety**: Enforce `enum class Zone` to prevent accidental integer conversions.
3. **Immutability of Rules**: All rate cards must be encapsulated in `constexpr` arrays to guarantee compile-time evaluation and single-point updateability.
4. **Encapsulation**: SmartCard balance must be strictly private with validated mutation operations.

### 2. Fare Revision Management
- To revise fares across the entire network, modify only the `BASE_PAISE` array and recompile. Zero application logic changes required.

### Output Log
```
=== Final Production Design Summary ===
Architecture: Strongly-typed OOP with static constexpr configuration.
Financial Storage: 64-bit integer paise (long long).
Safety Invariant: Hard minimum balance of Rs 50

```
