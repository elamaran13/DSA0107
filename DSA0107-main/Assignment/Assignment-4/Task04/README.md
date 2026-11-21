# Assignment 4 - CO4: Designing Reusable Class Hierarchies & Pointers
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 04: Pointers to Derived Classes: Forensics

### 1. Forensics Analysis of Output
- `p->rate()`: Non-virtual call. Resolved statically at compile-time based on the pointer type (`Account*`), invoking `Account::rate()`, which returns `3.5`.
- `p->vrate()`: Virtual call. Resolved dynamically at runtime via the virtual method table (vtable). Points to actual object `SeniorAccount`, returning `4.0`.
- `copy.vrate()`: **Object Slicing**. `Account copy = s;` passes `SeniorAccount` by value to `Account`'s copy constructor. The derived fields and vtable pointer are stripped away (sliced). `copy` is purely an `Account`, hence `copy.vrate()` returns `3.5`.

### 2. Output Verification
Expected Output:
```
3.5 4 3.5
```
Actual Output:
```
3.5 4 3.5
```
Matches expected output with 100% precision.

### 3. Virtual Destructor Mandate
Base classes intended for polymorphic destruction must declare a `virtual ~Base() = default;`. Otherwise, `delete p;` on an `Account*` pointing to `SeniorAccount` invokes only `~Account()`, causing memory leaks of derived resources.

### Output Log
```
3.5 4 3.5

```
