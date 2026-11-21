# Assignment 1 - CO1: Metro Smart-Card Fare System
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task 09: Implement and Test the Fare Logic

### 1. Automated Test Suite Execution
Six comprehensive test cases were designed and executed covering:
1. Normal off-peak operations across zones.
2. Boundary hours (08:00 AM, 10:00 AM, 17:00 PM, 20:00 PM).
3. Exact minimum balance boundary: Balance Rs 60 with Fare Rs 10 leaves exactly Rs 50 (Granted).
4. Insufficient balance: Balance Rs 59.99 with Fare Rs 10 leaves Rs 49.99 < Rs 50 (Denied).

### 2. Execution Log
```
=== Test Suite: Metro Fare Logic Validation ===
[PASS] Normal Inner Off-Peak (12:00) | Fare: Rs 10 | Allowed: YES
[PASS] Peak Inner Boundary 8:00 AM | Fare: Rs 12 | Allowed: YES
[PASS] Off-Peak Boundary 10:00 AM | Fare: Rs 10 | Allowed: YES
[PASS] Peak Evening Boundary 17:00 | Fare: Rs 36 | Allowed: YES
[PASS] Exact Min Balance Remaining | Fare: Rs 10 | Allowed: YES
[PASS] Insufficient Balance by 1 Paisa | Fare: Rs 10 | Allowed: NO

Test Suite Result: 6/6 Passed.
```
All boundary and invariant assertions passed.

### Output Log
```
=== Test Suite: Metro Fare Logic Validation ===
[PASS] Normal Inner Off-Peak (12:00) | Fare: Rs 10 | Allowed: YES
[PASS] Peak Inner Boundary 8:00 AM | Fare: Rs 12 | Allowed: YES
[PASS] Off-Peak Boundary 10:00 AM | Fare: Rs 10 | Allowed: YES
[PASS] Peak Evening Boundary 17:00 | Fare: Rs 36 | Allowed: YES
[PASS] Exact Min Balance Remaining | Fare: Rs 10 | Allowed: YES
[PASS] Insufficient Balance by 1 Paisa | Fare: Rs 10 | Allowed: NO

Test Suite Result: 6/6 Passed.

```
