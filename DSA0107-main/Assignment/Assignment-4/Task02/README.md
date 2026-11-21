# Assignment 4 - CO4: Designing Reusable Class Hierarchies & Pointers
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 02: From Requirement to Hierarchy (University People & Diamond Resolution)

### 1. Identifying the Relationships (Task 2.1)
- `Student` IS-A `Person`.
- `Staff` IS-A `Person`.
- `TeachingAssistant` IS-A `Student` AND IS-A `Staff` (Multiple Inheritance).

### 2. Diamond Problem and Virtual Base Classes (Task 2.2)
- Without `virtual` inheritance, a `TeachingAssistant` object receives two independent copies of `Person` (one via `Student`, one via `Staff`). This produces:
  1. Storage overhead and duplicate state.
  2. Ambiguity when accessing `name` or `id` (`ta.name` triggers compiler error `error: request for member 'name' is ambiguous`).
- **Resolution**: Both `Student` and `Staff` inherit from `Person` using `virtual public Person`. The compiler ensures only ONE shared subobject of `Person` is instantiated.

### 3. Order of Construction
The most derived class (`TeachingAssistant`) is responsible for directly calling the virtual base constructor `Person(n, i, p)`.

### Output Log
```
=== University Hierarchy & Diamond Problem Resolution ===
[Person constructed: Kalaichelvan]
[Student constructed: B.Tech CSE]
[Staff constructed: CS Dept]
[TeachingAssistant constructed: 10 hrs/wk]

Displaying TA Details:
ID: 192421298 | Name: Kalaichelvan | Phone: 9876543210 | Prog: B.Tech CSE | CGPA: 9.4 | Dept: CS Dept | TA Hours: 10

```
