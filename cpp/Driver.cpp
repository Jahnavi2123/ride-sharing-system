#include "Driver.h"
#include <iostream>
#include <iomanip>

Driver::Driver(const std::string& driverID,
               const std::string& name,
               double rating)
    : driverID(driverID), name(name), rating(rating) {
}

void Driver::addRide(const std::shared_ptr<Ride>& ride) {
    assignedRides.push_back(ride);
}

void Driver::getDriverInfo() const {
    std::cout << "Driver ID: " << driverID << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Rating: " << std::fixed
              << std::setprecision(1) << rating << '\n';
}

void Driver::viewAssignedRides() const {
    std::cout << "\nCompleted Rides:\n";

    if (assignedRides.empty()) {
        std::cout << "No rides assigned.\n";
        return;
    }

    for (const auto& ride : assignedRides) {
        std::cout << ride->getRideID()
                  << " - " << ride->getRideType()
                  << " - $" << std::fixed << std::setprecision(2)
                  << ride->fare() << '\n';
    }
}