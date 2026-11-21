# Assignment 2 - CO2: Functions and Classes in C++
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 07 (Q7): Day-4 Design Challenge - Diagnose, Redesign and Validate

### 1. Diagnosis of Limitation in Original System (Q5)
- In the initial `BusTicket` implementation, seat allocation relies on a simple monotonically increasing static counter (`++issued`).
- **Defects identified**:
  1. Once tickets reach `CAPACITY`, no further tickets can ever be booked.
  2. If a passenger cancels or misses the bus, their seat cannot be reclaimed because the static counter never decrements or tracks individual seat occupancy.
  3. Memory allocation across arrays of static objects leads to unrecyclable slots.

### 2. Architectural Redesign
- Replaced the static counter with an encapsulated `SmartBusManager` managing a bit-mapped boolean occupancy vector `seatMap`.
- Enabled dynamic reservation, cancellation, and seat recycling (`O(1)` or `O(C)` search).

### 3. Validation Log
```
=== Day-4 Design Challenge: Redesigned Bus Reservation System ===
Asha assigned Seat 1
Bala assigned Seat 2
Chitra assigned Seat 3
Dev placed on Waiting List (Full)
Seat 2 cancelled and released for reallocation.
Dev assigned Seat 2
Final Active Bookings: 3/3
```
Proves that cancelled seats are immediately reassigned to waiting commuters, resolving the static counter defect.

### Output Log
```
=== Day-4 Design Challenge: Redesigned Bus Reservation System ===
Asha assigned Seat 1
Bala assigned Seat 2
Chitra assigned Seat 3
Dev placed on Waiting List (Full)
Seat 2 cancelled and released for reallocation.
Dev assigned Seat 2
Final Active Bookings: 3/3

```
