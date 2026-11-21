# Assignment 5 - CO5: Polymorphism and Exception Handling
**Student Name:** Kalaichelvan J
**Register Number:** 192421298
**Course:** Object Oriented Programming with C++ (DSA01)
**Compiler:** g++ 16.2.0 (MinGW-W64)
**Flags:** -std=c++17 -Wall -Wextra

---

## Task A3: Design with Abstract Classes (Payer Interface)

### 1. Payer Abstract Strategy
The abstract class `Payer` defines the contract:
```cpp
class Payer {
public:
    virtual ~Payer() = default;
    virtual std::string name() const = 0;
    virtual double amountCovered(const Bill& b) const = 0;
};
```
### 2. Extensible Payer Implementations
- `SelfPay`: 0% coverage.
- `InsurancePayer`: Applies co-pay deductions (`(1 - copay) * total`) capped at `maxCover`.
- `GovtScheme`: Capped fixed reimbursement.
Adding new payers (e.g. `CharityTrustPayer`) requires zero modifications to existing billing classes (Open/Closed Principle).

### Output Log
```
Bill Amount: Rs 45000
Insurance Covered: Rs 40500
Govt Scheme Covered: Rs 30000

```
