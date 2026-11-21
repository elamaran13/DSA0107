// Q3: Dynamic Constructors and Destructors (Auditorium Seat Booking)
#include <iostream>
#include <iomanip>

class Auditorium {
private:
    int rows;
    int cols;
    int** seats; // Dynamic 2D matrix

public:
    Auditorium(int r, int c) : rows(r), cols(c) {
        seats = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            seats[i] = new int[cols](); // zero-initialized
        }
        std::cout << "Auditorium created with " << rows << " rows and " << cols << " columns.\n";
    }

    bool bookSeat(int r, int c) {
        if (r >= 0 && r < rows && c >= 0 && c < cols && seats[r][c] == 0) {
            seats[r][c] = 1; // Booked
            return true;
        }
        return false;
    }

    void display() const {
        std::cout << "Seat Layout (0=Available, 1=Booked):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << (seats[i][j] ? "[X]" : "[ ]") << " ";
            }
            std::cout << "\n";
        }
    }

    ~Auditorium() {
        for (int i = 0; i < rows; ++i) {
            delete[] seats[i];
        }
        delete[] seats;
        std::cout << "Auditorium seat map memory safely deallocated.\n";
    }
};

int main() {
    {
        Auditorium hall(3, 4);
        hall.bookSeat(0, 1);
        hall.bookSeat(1, 2);
        hall.bookSeat(2, 3);
        hall.display();
    } // Out of scope -> destructor called automatically
    return 0;
}
