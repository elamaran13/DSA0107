# Assignment 4 - CO4: Designing Reusable Class Hierarchies & Pointers
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 03: Constructors in Derived Classes and Member Classes

### 1. Implementation of Completed Code
- `TODO 1`: Constructed member initialization list:
  ```cpp
  Student(const std::string& n, int a, long long r, const std::string& c, int p)
      : Person(n, a), regNo(r), home(c, p) {}
  ```
- Synthesizes base class initialization (`Person(n, a)`), primitive member (`regNo(r)`), and composite object (`home(c, p)`).

### 2. Output Verification
Expected Output:
```
192311001 Kavya (19) Salem-636001
```
Actual Output:
```
192311001 Kavya (19) Salem-636001
```
Matches expected specification with 100% precision.

### 3. Construction Order Rules
1. Virtual base classes (if any) first.
2. Non-virtual base classes in the order they appear in the class declaration list (`Person`).
3. Member objects in the order of their declaration in the class body (`regNo`, then `home`).
4. Derived class constructor body executes last.

### Output Log
```
192311001 Kavya (19) Salem-636001

```
