// Task 1: Class Design Review - Diagnosing and Repairing Duplicated Payroll Classes
#include <iostream>
#include <string>
#include <vector>

// Abstract Base Class
class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(const std::string& n, int i) : name(n), id(i) {}
    virtual ~Employee() = default;

    std::string getName() const { return name; }
    int getId() const { return id; }
    virtual double calculatePay() const = 0; // Pure virtual
};

// Salaried Staff Base
class SalariedEmployee : public Employee {
protected:
    double basic;
    static constexpr double DA_PERCENT = 0.42;
public:
    SalariedEmployee(const std::string& n, int i, double b)
        : Employee(n, i), basic(b) {}

    double calculatePay() const override {
        return basic + (basic * DA_PERCENT);
    }
};

class Professor : public SalariedEmployee {
private:
    double researchAllowance;
public:
    Professor(const std::string& n, int i, double b, double r)
        : SalariedEmployee(n, i, b), researchAllowance(r) {}

    double calculatePay() const override {
        return SalariedEmployee::calculatePay() + researchAllowance;
    }
};

class LabAssistant : public SalariedEmployee {
public:
    LabAssistant(const std::string& n, int i, double b)
        : SalariedEmployee(n, i, b) {}
};

class GuestFaculty : public Employee {
private:
    double hours;
    double hourlyRate;
public:
    GuestFaculty(const std::string& n, int i, double h, double r)
        : Employee(n, i), hours(h), hourlyRate(r) {}

    double calculatePay() const override {
        return hours * hourlyRate;
    }
};

int main() {
    std::cout << "=== Repaired College Payroll Hierarchy ===\n";
    std::vector<Employee*> staff = {
        new Professor("Dr. Raman", 101, 80000.0, 15000.0),
        new LabAssistant("Kannan", 202, 35000.0),
        new GuestFaculty("Prof. Smith", 303, 40.0, 1200.0)
    };

    for (const auto& emp : staff) {
        std::cout << "ID: " << emp->getId() << " | Name: " << emp->getName()
                  << " | Pay: Rs " << emp->calculatePay() << "\n";
        delete emp;
    }
    return 0;
}
