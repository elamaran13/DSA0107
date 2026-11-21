// Task 2: From Requirement to Hierarchy - University People & Diamond Resolution
#include <iostream>
#include <string>

// Virtual base class Person to resolve diamond problem
class Person {
protected:
    std::string name;
    int id;
    std::string phone;
public:
    Person(const std::string& n, int i, const std::string& p)
        : name(n), id(i), phone(p) {
        std::cout << "[Person constructed: " << name << "]\n";
    }
    virtual ~Person() = default;

    virtual void display() const {
        std::cout << "ID: " << id << " | Name: " << name << " | Phone: " << phone;
    }
};

class Student : virtual public Person {
protected:
    std::string programme;
    double cgpa;
public:
    Student(const std::string& n, int i, const std::string& p, const std::string& prog, double c)
        : Person(n, i, p), programme(prog), cgpa(c) {
        std::cout << "[Student constructed: " << prog << "]\n";
    }

    void display() const override {
        Person::display();
        std::cout << " | Programme: " << programme << " | CGPA: " << cgpa;
    }
};

class Staff : virtual public Person {
protected:
    std::string department;
    double salary;
public:
    Staff(const std::string& n, int i, const std::string& p, const std::string& dept, double sal)
        : Person(n, i, p), department(dept), salary(sal) {
        std::cout << "[Staff constructed: " << dept << "]\n";
    }

    void display() const override {
        Person::display();
        std::cout << " | Dept: " << department << " | Salary: Rs " << salary;
    }
};

// Diamond resolved: TeachingAssistant derives from both Student and Staff
class TeachingAssistant : public Student, public Staff {
private:
    int hoursPerWeek;
public:
    TeachingAssistant(const std::string& n, int i, const std::string& p,
                      const std::string& prog, double c,
                      const std::string& dept, double sal, int hrs)
        : Person(n, i, p), // Most derived class directly initializes virtual base!
          Student(n, i, p, prog, c),
          Staff(n, i, p, dept, sal),
          hoursPerWeek(hrs) {
        std::cout << "[TeachingAssistant constructed: " << hrs << " hrs/wk]\n";
    }

    void display() const override {
        Person::display();
        std::cout << " | Prog: " << programme << " | CGPA: " << cgpa
                  << " | Dept: " << department << " | TA Hours: " << hoursPerWeek << "\n";
    }
};

int main() {
    std::cout << "=== University Hierarchy & Diamond Problem Resolution ===\n";
    TeachingAssistant ta("Kalaichelvan", 192421298, "9876543210", "B.Tech CSE", 9.4, "CS Dept", 15000.0, 10);
    std::cout << "\nDisplaying TA Details:\n";
    ta.display();
    return 0;
}
