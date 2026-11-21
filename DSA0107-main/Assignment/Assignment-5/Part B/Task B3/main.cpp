// Part B - Task B3: Virtual Functions vs Switch vs Exceptions - Benchmark & Analysis
#include <iostream>
#include <chrono>
#include <vector>

// Approach A: Virtual Functions
class VBill {
public:
    virtual ~VBill() = default;
    virtual double total() const = 0;
};

class VOutPatient : public VBill {
    double c, t;
public:
    VOutPatient(double c_, double t_) : c(c_), t(t_) {}
    double total() const override { return c + t; }
};

class VInPatient : public VBill {
    int d; double r, s;
public:
    VInPatient(int d_, double r_, double s_) : d(d_), r(r_), s(s_) {}
    double total() const override { return d * r + s; }
};

// Approach B: Switch on Enum
enum class BillType { OP, IP };
struct SBill {
    BillType type;
    double c, t;
    int d; double r, s;

    double total() const {
        switch (type) {
            case BillType::OP: return c + t;
            case BillType::IP: return d * r + s;
        }
        return 0;
    }
};

int main() {
    const int N = 1000000;
    std::cout << "=== Performance Comparison across 1,000,000 Invocations ===\n";

    // 1. Virtual Functions
    std::vector<VBill*> vList;
    vList.reserve(N);
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) vList.push_back(new VOutPatient(500, 1200));
        else vList.push_back(new VInPatient(3, 2500, 40000));
    }

    auto startV = std::chrono::high_resolution_clock::now();
    double vSum = 0;
    for (int i = 0; i < N; ++i) vSum += vList[i]->total();
    auto endV = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedV = endV - startV;

    // 2. Switch Statement
    std::vector<SBill> sList(N);
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) sList[i] = {BillType::OP, 500, 1200, 0, 0, 0};
        else sList[i] = {BillType::IP, 0, 0, 3, 2500, 40000};
    }

    auto startS = std::chrono::high_resolution_clock::now();
    double sSum = 0;
    for (int i = 0; i < N; ++i) sSum += sList[i].total();
    auto endS = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedS = endS - startS;

    std::cout << "Virtual Method Total: " << vSum << " | Time: " << elapsedV.count() << " ms\n";
    std::cout << "Switch-based  Total: " << sSum << " | Time: " << elapsedS.count() << " ms\n";

    for (auto p : vList) delete p;
    return 0;
}
