// Part A - Task A3: Design with Abstract Classes (Payer Interface)
#include <iostream>
#include <string>
#include <algorithm>

class Bill {
public:
    virtual ~Bill() = default;
    virtual double total() const = 0;
};

class MockBill : public Bill {
    double amt;
public:
    explicit MockBill(double a) : amt(a) {}
    double total() const override { return amt; }
};

// Abstract Payer Strategy
class Payer {
public:
    virtual ~Payer() = default;
    virtual std::string name() const = 0;
    virtual double amountCovered(const Bill& b) const = 0;
};

class SelfPay : public Payer {
public:
    std::string name() const override { return "Self-Pay"; }
    double amountCovered(const Bill&) const override { return 0.0; } // Patient pays 100%
};

class InsurancePayer : public Payer {
private:
    double maxCover;
    double copayPercent;
public:
    InsurancePayer(double maxC, double copay) : maxCover(maxC), copayPercent(copay) {}
    std::string name() const override { return "Corporate Insurance"; }
    double amountCovered(const Bill& b) const override {
        double eligible = b.total() * (1.0 - copayPercent / 100.0);
        return std::min(eligible, maxCover);
    }
};

class GovtScheme : public Payer {
private:
    double capAmount;
public:
    explicit GovtScheme(double cap) : capAmount(cap) {}
    std::string name() const override { return "Govt Health Scheme"; }
    double amountCovered(const Bill& b) const override {
        return std::min(b.total(), capAmount);
    }
};

int main() {
    MockBill b(45000);
    InsurancePayer ins(50000, 10); // 10% copay, 50000 max
    GovtScheme govt(30000);

    std::cout << "Bill Amount: Rs " << b.total() << "\n";
    std::cout << "Insurance Covered: Rs " << ins.amountCovered(b) << "\n";
    std::cout << "Govt Scheme Covered: Rs " << govt.amountCovered(b) << "\n";
    return 0;
}
