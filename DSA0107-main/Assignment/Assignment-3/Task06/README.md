# Assignment 3 - CO3: Constructors, Destructors and Operator Overloading
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 06 (Q6): The Rules of Operator Overloading

### 1. Fundamental Rules of Operator Overloading in C++
1. **Precedence and Associativity**: Cannot be modified (e.g. `*` always binds tighter than `+`).
2. **Arity**: Cannot be altered (unary operators remain unary, binary remain binary).
3. **New Operators**: Cannot invent non-existent operators (like `**` or `<=>` prior to C++20).
4. **Non-Overloadable Operators**:
   - Scope resolution (`::`)
   - Member access (`.`)
   - Pointer-to-member (`.*`)
   - Conditional ternary (`?:`)
   - `sizeof`, `typeid`
5. **Class Types Required**: At least one operand must be a user-defined class/struct/enum type.

### Output Log
```
Hello, World!

```
