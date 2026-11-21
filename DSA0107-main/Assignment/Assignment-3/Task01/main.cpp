// Q1: Constructors and Constructor Overloading (Library Book Records)
#include <iostream>
#include <string>

class Book {
private:
    std::string isbn;
    std::string title;
    std::string author;
    double price;

public:
    // Default constructor
    Book() : isbn("UNKNOWN"), title("Untitled"), author("Anonymous"), price(0.0) {}

    // Donated book (title & author known, price = 0)
    Book(const std::string& t, const std::string& a)
        : isbn("DONATED"), title(t), author(a), price(0.0) {}

    // Fully specified new book
    Book(const std::string& i, const std::string& t, const std::string& a, double p)
        : isbn(i), title(t), author(a), price(p) {}

    void display() const {
        std::cout << "ISBN: " << isbn << " | \"" << title << "\" by " << author
                  << " | Price: Rs " << price << "\n";
    }
};

int main() {
    std::cout << "=== Library Book Catalog (Constructor Overloading) ===\n";
    Book b1;
    Book b2("Data Structures in C++", "Mark Allen Weiss");
    Book b3("978-0131103627", "The C Programming Language", "Kernighan & Ritchie", 650.0);

    b1.display();
    b2.display();
    b3.display();

    return 0;
}
