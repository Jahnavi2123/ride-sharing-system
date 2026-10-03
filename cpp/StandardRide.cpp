#include "StandardRide.h"

StandardRide::StandardRide(const std::string& rideID,
                           const std::string& pickupLocation,
                           const std::string& dropoffLocation,
                           double distance)
    : Ride(rideID, pickupLocation, dropoffLocation, distance) {
}

double StandardRide::fare() const {
    return getDistance() * RATE_PER_MILE;
}

std::string StandardRide::getRideType() const {
    return "Standard";
}