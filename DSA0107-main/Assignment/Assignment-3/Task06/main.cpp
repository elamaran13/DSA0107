// Q6: Rules of Operator Overloading & Text Class
#include <iostream>
#include <cstring>

class Text {
private:
    char* str;
public:
    Text(const char* s = "") {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }

    Text(const Text& other) {
        str = new char[std::strlen(other.str) + 1];
        std::strcpy(str, other.str);
    }

    Text& operator=(const Text& other) {
        if (this != &other) {
            delete[] str;
            str = new char[std::strlen(other.str) + 1];
            std::strcpy(str, other.str);
        }
        return *this;
    }

    // Concatenation operator +
    Text operator+(const Text& other) const {
        char* temp = new char[std::strlen(str) + std::strlen(other.str) + 1];
        std::strcpy(temp, str);
        std::strcat(temp, other.str);
        Text res(temp);
        delete[] temp;
        return res;
    }

    ~Text() {
        delete[] str;
    }

    void display() const { std::cout << str << "\n"; }
};

int main() {
    Text t1("Hello, ");
    Text t2("World!");
    Text t3 = t1 + t2;
    t3.display();
    return 0;
}
