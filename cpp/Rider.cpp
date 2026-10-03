#include "Rider.h"
#include <iostream>
#include <iomanip>

Rider::Rider(const std::string& riderID,
             const std::string& name)
    : riderID(riderID), name(name) {
}

void Rider::requestRide(const std::shared_ptr<Ride>& ride) {
    requestedRides.push_back(ride);
}

void Rider::getRiderInfo() const {
    std::cout << "Rider ID: " << riderID << '\n';
    std::cout << "Name: " << name << '\n';
}

void Rider::viewRides() const {
    std::cout << "\nRide History:\n";

    if (requestedRides.empty()) {
        std::cout << "No rides requested.\n";
        return;
    }

    for (const auto& ride : requestedRides) {
        std::cout << ride->getRideID()
                  << " - " << ride->getRideType()
                  << " - $" << std::fixed << std::setprecision(2)
                  << ride->fare() << '\n';
    }
}