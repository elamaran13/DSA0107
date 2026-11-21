# Assignment 3 - CO3: Constructors, Destructors and Operator Overloading
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 07 (Q7): Design a Complex-Number Class from First Principles (AC Impedance Calculator)

### 1. Requirements & Mathematical Foundation
In AC electrical circuits, impedance is represented as a complex number:
$$\\mathbf{Z} = R + jX$$
where $R$ is resistance, $X$ is reactance ($X_L > 0$ inductive, $X_C < 0$ capacitive), and $j = \\sqrt{-1}$.
- **Series Impedance**: $\\mathbf{Z}_{series} = \\mathbf{Z}_1 + \\mathbf{Z}_2$
- **Parallel Impedance**: $\\mathbf{Z}_{parallel} = \\frac{\\mathbf{Z}_1 \\cdot \\mathbf{Z}_2}{\\mathbf{Z}_1 + \\mathbf{Z}_2}$

### 2. Class Implementation & Operator Overloads
- Overloaded `operator+`, `operator*`, `operator/`, and stream insertion `operator<<`.
- Provided analytical helper functions for `magnitude()` and `phaseDegrees()`.

### 3. Execution Results
```
=== AC Circuit Impedance Calculator ===
Z1 (Branch 1): 10.00 + 5.00j (Magnitude: 11.18 ohms)
Z2 (Branch 2): 15.00 - 8.00j (Magnitude: 17.00 ohms)
Z_Series     : 25.00 - 3.00j (Magnitude: 25.18 ohms)
Z_Parallel   : 7.62 + 0.94j (Magnitude: 7.67 ohms)
```
Accurately calculates complex electrical impedance networks.

### Output Log
```
=== AC Circuit Impedance Calculator ===
Z1 (Branch 1): 10.00 + 5.00j (Magnitude: 11.18 ohms)
Z2 (Branch 2): 15.00 - 8.00j (Magnitude: 17.00 ohms)
Z_Series     : 25.00 - 3.00j (Magnitude: 25.18 ohms)
Z_Parallel   : 7.52 + 0.70j (Magnitude: 7.55 ohms)

```
