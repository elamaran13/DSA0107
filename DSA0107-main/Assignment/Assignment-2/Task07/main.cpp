// Q7: Day-4 Design Challenge - Diagnosing & Redesigning Seat Allocation Engine
#include <iostream>
#include <string>
#include <vector>

// Redesigned dynamic seat ticket allocation system with seat reclamation
class SmartBusManager {
private:
    int capacity;
    int activeBookings;
    std::vector<bool> seatMap; // true if occupied

public:
    explicit SmartBusManager(int cap) : capacity(cap), activeBookings(0), seatMap(cap + 1, false) {}

    int bookSeat(const std::string& passenger) {
        for (int s = 1; s <= capacity; ++s) {
            if (!seatMap[s]) {
                seatMap[s] = true;
                activeBookings++;
                std::cout << passenger << " assigned Seat " << s << "\n";
                return s;
            }
        }
        std::cout << passenger << " placed on Waiting List (Full)\n";
        return 0;
    }

    bool cancelSeat(int seatNo) {
        if (seatNo >= 1 && seatNo <= capacity && seatMap[seatNo]) {
            seatMap[seatNo] = false;
            activeBookings--;
            std::cout << "Seat " << seatNo << " cancelled and released for reallocation.\n";
            return true;
        }
        return false;
    }

    int getActiveCount() const { return activeBookings; }
};

int main() {
    std::cout << "=== Day-4 Design Challenge: Redesigned Bus Reservation System ===\n";
    SmartBusManager bus(3);
    int s1 = bus.bookSeat("Asha");
    int s2 = bus.bookSeat("Bala");
    int s3 = bus.bookSeat("Chitra");
    int s4 = bus.bookSeat("Dev"); // Waiting

    // Demonstrate flaw in static monotonically increasing counter:
    // If Bala cancels, seat 2 should be reusable by Dev!
    bus.cancelSeat(s2);
    int sDev = bus.bookSeat("Dev"); // Dev gets reassigned released Seat 2!

    std::cout << "Final Active Bookings: " << bus.getActiveCount() << "/3\n";
    return 0;
}
