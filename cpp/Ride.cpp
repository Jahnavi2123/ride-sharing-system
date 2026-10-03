#include "Ride.h"
#include <iostream>
#include <iomanip>

Ride::Ride(const std::string& rideID,
           const std::string& pickupLocation,
           const std::string& dropoffLocation,
           double distance)
    : rideID(rideID),
      pickupLocation(pickupLocation),
      dropoffLocation(dropoffLocation),
      distance(distance) {
}

std::string Ride::getRideID() const {
    return rideID;
}

std::string Ride::getPickupLocation() const {
    return pickupLocation;
}

std::string Ride::getDropoffLocation() const {
    return dropoffLocation;
}

double Ride::getDistance() const {
    return distance;
}

void Ride::rideDetails() const {
    std::cout << "Ride ID: " << rideID << '\n';
    std::cout << "Type: " << getRideType() << '\n';
    std::cout << "Pickup: " << pickupLocation << '\n';
    std::cout << "Drop-off: " << dropoffLocation << '\n';
    std::cout << "Distance: " << distance << " miles\n";
    std::cout << "Fare: $" << std::fixed << std::setprecision(2)
              << fare() << '\n';
}