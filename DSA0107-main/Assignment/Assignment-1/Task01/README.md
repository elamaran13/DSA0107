# Assignment 1 - CO1: Metro Smart-Card Fare System
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 01: Understand the Problem and Identify the Objects

### 1. Object-Oriented Analysis
The metro smart-card system operates on distinct real-world entities that are modeled as objects:
- **SmartCard**: Encapsulates card identity (`cardId`), monetary balance (`balancePaise`), and maintains invariant integrity (minimum balance of Rs 50). Provides behaviors: `deduct()`, `canTravel()`, `recharge()`.
- **Passenger**: Represents the commuter holding the card, with concession profiles (Regular, Senior, Student).
- **Journey**: Encapsulates entry/exit stations, entry timestamp, zone traversed, and peak-hour classification.
- **Zone**: Categorized as Inner (Rs 10), Middle (Rs 20), and Outer (Rs 30).
- **FareTable**: Maps travel zones and temporal multipliers into exact fare amounts.

### 2. Procedural vs Object-Oriented Comparison
- **Procedural Style**: Uses decoupled global/local variables (e.g., `double balance`, `int zone`) and free functions. Lacks data protection; any routine can corrupt `balance` or allow negative funds without checking minimum balance invariants.
- **Object-Oriented Style**: Encapsulates data and member functions inside classes with `private` access specifiers. State changes occur exclusively via audited public member methods.

### 3. OOP Principles Applied
- **Encapsulation**: State variables like `balancePaise` are hidden; updates require rule validation.
- **Abstraction**: External systems only call high-level operations such as `card.deduct(fare)` without knowing internal representation.
- **Inheritance & Polymorphism**: Extensible for varied card types (e.g., TouristCard, MonthlyPass) inheriting base properties.

### 4. Alternative Concept and Complexity Analysis
- Using free functional procedural code vs class encapsulation yields identical time complexity O(1) for single deductions and space complexity O(1) per card. However, object encapsulation prevents runtime state corruption bugs and architectural decay.

### Output Log
```
Card ID: METRO1001
Initial Balance: Rs 100
Deducted Rs 36. New Balance: Rs 64
Denied: Minimum balance of Rs 50.00 required. Current Balance: Rs 64

```
