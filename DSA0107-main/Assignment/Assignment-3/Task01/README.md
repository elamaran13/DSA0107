# Assignment 3 - CO3: Constructors, Destructors and Operator Overloading
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 01 (Q1): Constructors and Constructor Overloading

### 1. Constructor Design and Member Initializer Lists
- Implemented three overloaded constructors in `Book`:
  1. Default constructor (`Book()`) initializes default placeholder values.
  2. Partial constructor (`Book(title, author)`) handles donated books with zero purchase price.
  3. Full constructor (`Book(isbn, title, author, price)`) initializes complete catalog records.
- All constructors use C++ **Member Initializer Lists** (`: member(val)`), ensuring direct initialization without default construction followed by assignment.

### 2. Output Verification
```
=== Library Book Catalog (Constructor Overloading) ===
ISBN: UNKNOWN | "Untitled" by Anonymous | Price: Rs 0
ISBN: DONATED | "Data Structures in C++" by Mark Allen Weiss | Price: Rs 0
ISBN: 978-0131103627 | "The C Programming Language" by Kernighan & Ritchie | Price: Rs 650
```

### Output Log
```
=== Library Book Catalog (Constructor Overloading) ===
ISBN: UNKNOWN | "Untitled" by Anonymous | Price: Rs 0
ISBN: DONATED | "Data Structures in C++" by Mark Allen Weiss | Price: Rs 0
ISBN: 978-0131103627 | "The C Programming Language" by Kernighan & Ritchie | Price: Rs 650

```
