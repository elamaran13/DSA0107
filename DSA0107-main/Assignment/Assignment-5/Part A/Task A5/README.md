# Assignment 5 - CO5: Polymorphism and Exception Handling
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task A5: Design Recovery and Rethrowing

### 1. Rethrowing Semantics with `throw;`
- In intermediate components (e.g. logging/auditing layers), exceptions must be inspected without swallowing them.
- Using `throw;` (bare throw) re-raises the exact original polymorphic exception without object slicing. (Using `throw e;` would slice derived exception types to the base caught type!).

### 2. RAII and Exception Safety
- C++ guarantees stack unwinding during exception propagation. All local automatic objects and smart pointers (`std::unique_ptr`) are destructed in reverse order of construction, ensuring no memory or file descriptor leaks.

### Output Log
```
[AUDIT LOG] Intercepted Exception: Claim exceeds policy limit!
[TOP LEVEL HANDLER] Final Disposition: Claim exceeds policy limit!

```
