#include "SharedRide.h"

SharedRide::SharedRide(const std::string& rideID,
                       const std::string& pickupLocation,
                       const std::string& dropoffLocation,
                       double distance)
    : Ride(rideID, pickupLocation, dropoffLocation, distance) {
}

double SharedRide::fare() const {
    return getDistance() * RATE_PER_MILE;
}

std::string SharedRide::getRideType() const {
    return "Shared";
}