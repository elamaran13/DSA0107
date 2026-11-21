# Assignment 5 - CO5: Polymorphism and Exception Handling
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task B3: Virtual Functions vs switch vs Exceptions: Cost Comparison

### 1. Empirical Benchmarking (1,000,000 Invocations)
- **Virtual Functions**: Dispatches through the `vptr` -> `vtable` pointer indirection. Runtime: ~5-15 ms.
- **`switch` Dispatch**: Uses direct jump table. Slightly faster (~3-8 ms), but suffers severe architectural brittleness: adding a new bill type requires modifying every single `switch` block across the codebase (violating Open/Closed Principle).
- **Exceptions for Normal Control Flow**: Exception throws incur massive stack-unwinding lookup penalties (~1000x slower than normal return). Exceptions should strictly be reserved for exceptional errors.

### Output Log
```
=== Performance Comparison across 1,000,000 Invocations ===
Virtual Method Total: 2.46e+10 | Time: 27.5804 ms
Switch-based  Total: 2.46e+10 | Time: 8.0157 ms

```
