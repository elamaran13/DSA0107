// Part A - Task A1: Polymorphic Bill Hierarchy Design
#include <iostream>
#include <string>
#include <vector>

class Bill {
protected:
    std::string patientName;
public:
    explicit Bill(const std::string& p) : patientName(p) {}
    virtual ~Bill() = default;

    virtual std::string type() const = 0;
    virtual double total() const = 0;
    virtual void print() const {
        std::cout << type() << " [" << patientName << "] Total: Rs " << total() << "\n";
    }
};

class OutPatientBill : public Bill {
private:
    double consultationFee;
    double labCharges;
public:
    OutPatientBill(const std::string& p, double c, double l)
        : Bill(p), consultationFee(c), labCharges(l) {}

    std::string type() const override { return "OP"; }
    double total() const override { return consultationFee + labCharges; }
};

class InPatientBill : public Bill {
private:
    int days;
    double roomRentPerDay;
    double surgeryCharges;
public:
    InPatientBill(const std::string& p, int d, double r, double s)
        : Bill(p), days(d), roomRentPerDay(r), surgeryCharges(s) {}

    std::string type() const override { return "IP"; }
    double total() const override { return (days * roomRentPerDay) + surgeryCharges; }
};

int main() {
    std::vector<Bill*> bills = {
        new OutPatientBill("Ravi", 500, 1200),
        new InPatientBill("Meena", 3, 2500, 40000)
    };

    double grandTotal = 0;
    for (const auto& b : bills) {
        b->print();
        grandTotal += b->total();
        delete b;
    }
    std::cout << "Grand Total: Rs " << grandTotal << "\n";
    return 0;
}
