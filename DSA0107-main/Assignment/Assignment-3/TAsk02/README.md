# Assignment 3 - CO3: Constructors, Destructors and Operator Overloading
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 02 (Q2): Copy Constructors: Shallow and Deep Copies

### 1. Implementation of Completed Code
- `TODO 1 (Deep Copy Constructor)`: Dynamically allocates an independent array `new std::string[other.n]` and copies elements across.
- `TODO 2 (Copy Assignment Operator)`: Guards against self-assignment (`this != &other`), allocates new storage first for strong exception safety, frees old resources with `delete[]`, updates pointers, and returns `*this`.
- `TODO 3 (Destructor)`: Invokes `delete[] medicines;` to eliminate heap leaks.

### 2. Output Verification
Expected Output:
```
Ibuprofen ORS | Paracetamol Cetirizine | Paracetamol ORS
```
Actual Output:
```
Ibuprofen ORS | Paracetamol Cetirizine | Paracetamol ORS
```
Matches expected specification with 100% precision.

### 3. Shallow vs Deep Copy Analysis
- Default memberwise copy (shallow copy) simply copies pointer addresses. As a result, multiple objects point to the same heap memory, leading to double-free crashes upon destruction and unintended cross-mutation. Deep copying ensures independent memory ownership.

### Output Log
```
Ibuprofen ORS | Paracetamol Cetirizine | Paracetamol ORS

```
