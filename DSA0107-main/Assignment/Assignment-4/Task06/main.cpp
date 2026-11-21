// Task 6: Vehicle Rental Fleet Design Challenge
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Vehicle {
protected:
    std::string registrationNumber;
    std::string model;
    double baseHourlyRate;
public:
    Vehicle(const std::string& reg, const std::string& m, double rate)
        : registrationNumber(reg), model(m), baseHourlyRate(rate) {}
    virtual ~Vehicle() = default;

    virtual std::string getType() const = 0;
    virtual double calculateRentalCost(int hours) const {
        return hours * baseHourlyRate;
    }

    virtual void display() const {
        std::cout << "[" << getType() << "] Reg: " << registrationNumber
                  << " | Model: " << model
                  << " | Rate/hr: Rs " << baseHourlyRate;
    }
};

class Bicycle : public Vehicle {
public:
    Bicycle(const std::string& reg, const std::string& m)
        : Vehicle(reg, m, 20.0) {}
    std::string getType() const override { return "Bicycle"; }
};

class TwoWheeler : public Vehicle {
protected:
    double fuelSurchargePerHour;
public:
    TwoWheeler(const std::string& reg, const std::string& m, double rate = 60.0, double fuel = 15.0)
        : Vehicle(reg, m, rate), fuelSurchargePerHour(fuel) {}

    std::string getType() const override { return "TwoWheeler"; }
    double calculateRentalCost(int hours) const override {
        return hours * (baseHourlyRate + fuelSurchargePerHour);
    }
};

class Car : public Vehicle {
protected:
    int seatingCapacity;
public:
    Car(const std::string& reg, const std::string& m, double rate = 150.0, int seats = 5)
        : Vehicle(reg, m, rate), seatingCapacity(seats) {}

    std::string getType() const override { return "Car"; }
    double calculateRentalCost(int hours) const override {
        double cost = hours * baseHourlyRate;
        if (hours > 10) cost *= 0.90; // 10% long-duration discount
        return cost;
    }
};

class ElectricCar : public Car {
private:
    double batteryLevelKWh;
public:
    ElectricCar(const std::string& reg, const std::string& m, double rate = 180.0, double battery = 50.0)
        : Car(reg, m, rate, 5), batteryLevelKWh(battery) {}

    std::string getType() const override { return "ElectricCar"; }
    double calculateRentalCost(int hours) const override {
        // Electric cars have green rebate: 5% flat off base rental
        return Car::calculateRentalCost(hours) * 0.95;
    }
};

int main() {
    std::cout << "=== Vehicle Rental Fleet Hierarchy ===\n";
    std::vector<Vehicle*> fleet = {
        new Bicycle("BK-01", "Hero Sprint"),
        new TwoWheeler("TN-09-AB-1234", "Honda Activa"),
        new Car("TN-07-CD-5678", "Hyundai Creta"),
        new ElectricCar("TN-01-EV-9999", "Tata Nexon EV")
    };

    int rentalHours = 12;
    std::cout << "Calculating rental cost for " << rentalHours << " hours across fleet:\n";
    for (const auto& v : fleet) {
        v->display();
        std::cout << " | Total Cost: Rs " << std::fixed << std::setprecision(2)
                  << v->calculateRentalCost(rentalHours) << "\n";
        delete v;
    }
    return 0;
}
