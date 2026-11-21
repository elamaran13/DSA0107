// Part B - Task B4: Final Engineering Decision & Extension
#include <iostream>
#include <string>
#include <vector>

// Core base
class Bill {
protected:
    std::string patient;
public:
    explicit Bill(const std::string& p) : patient(p) {}
    virtual ~Bill() = default;
    virtual std::string type() const = 0;
    virtual double total() const = 0;
};

// Existing Classes
class OutPatient : public Bill {
    double consultation, tests;
public:
    OutPatient(const std::string& p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}
    std::string type() const override { return "OP"; }
    double total() const override { return consultation + tests; }
};

// NEW EXTENSION: DayCareBill added without touching existing classes!
class DayCareBill : public Bill {
private:
    double procedureCost;
    double medicineCost;
public:
    DayCareBill(const std::string& p, double proc, double med)
        : Bill(p), procedureCost(proc), medicineCost(med) {}

    std::string type() const override { return "DayCare"; }
    double total() const override { return procedureCost + medicineCost; }
};

int main() {
    std::cout << "=== Hospital Billing Extensibility Demonstration ===\n";
    std::vector<Bill*> bills = {
        new OutPatient("Ravi", 500, 1200),
        new DayCareBill("Kavya", 8500, 3200) // Newly integrated seamlessly
    };

    for (const auto& b : bills) {
        std::cout << b->type() << " Bill: Rs " << b->total() << "\n";
        delete b;
    }
    return 0;
}
