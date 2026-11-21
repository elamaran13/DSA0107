# Assignment 3 - CO3: Constructors, Destructors and Operator Overloading
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 05 (Q5): Overloading Increment, Comparison and Subscript Operators

### 1. Operator Overload Mechanics
- **Prefix `++` (`TrackTimer& operator++()`)**: Increments the state and returns `*this` by reference, avoiding unnecessary temporaries.
- **Postfix `++` (`TrackTimer operator++(int)`)**: Takes a dummy `int` parameter to disambiguate from prefix. Copies the old state, increments current object, and returns the old copy by value.
- **Subscript `[]` (`operator[](size_t)`)**: Overloaded in both mutable (`std::string&`) and read-only (`const std::string&`) forms to support l-value array modifications.

### Output Log
```
Track at index 1: Track 2 - Fugue
Modified track at index 1: Track 2 - Scherzo
t: 12 | post: 10 | pre: 12

```
