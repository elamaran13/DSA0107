// Part A - Task A2: Understand Runtime Binding & Virtual Tables
#include <iostream>

struct Base {
    void nonVirtual() { std::cout << "Base::nonVirtual "; }
    virtual void vfunc() { std::cout << "Base::vfunc "; }
    virtual ~Base() = default;
};

struct Derived : public Base {
    void nonVirtual() { std::cout << "Derived::nonVirtual "; }
    void vfunc() override { std::cout << "Derived::vfunc "; }
};

int main() {
    Base* ptr = new Derived();
    // Early (compile-time) binding: binds to Base::nonVirtual
    ptr->nonVirtual();
    // Late (runtime) binding: looks up Derived's vtable entry for vfunc
    ptr->vfunc();
    delete ptr;
    std::cout << "\n";
    return 0;
}
