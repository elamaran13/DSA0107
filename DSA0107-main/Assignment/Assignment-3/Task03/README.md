# Assignment 3 - CO3: Constructors, Destructors and Operator Overloading
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 03 (Q3): Dynamic Constructors and Destructors

### 1. Dynamic 2D Allocation and RAII
- The constructor allocates dynamic memory on the heap using pointer-to-pointer (`int** seats`):
  1. Allocates an array of row pointers `new int*[rows]`.
  2. For each row, allocates an array of columns `new int[cols]()`.
- In compliance with RAII (Resource Acquisition Is Initialization), the destructor systematically iterates over every row, calling `delete[] seats[i]`, and finishes with `delete[] seats;`. This guarantees zero memory leakage.

### Output Log
```
Auditorium created with 3 rows and 4 columns.
Seat Layout (0=Available, 1=Booked):
[ ] [X] [ ] [ ] 
[ ] [ ] [X] [ ] 
[ ] [ ] [ ] [X] 
Auditorium seat map memory safely deallocated.

```
