// Task 4: Pointers to Derived Classes: Forensics & Virtual Functions
#include <iostream>

struct Account {
    double rate() const { return 3.5; }
    virtual double vrate() const { return 3.5; }
    virtual ~Account() = default;
};

struct SeniorAccount : Account {
    double rate() const { return 4.0; }
    double vrate() const override { return 4.0; }
};

int main() {
    SeniorAccount s;
    Account* p = &s;
    Account copy = s; // Object slicing occurs here!

    std::cout << p->rate() << ' ' << p->vrate() << ' ' << copy.vrate() << '\n';
    return 0;
}
