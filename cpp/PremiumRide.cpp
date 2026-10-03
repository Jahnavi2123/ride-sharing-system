#include "PremiumRide.h"

PremiumRide::PremiumRide(const std::string& rideID,
                         const std::string& pickupLocation,
                         const std::string& dropoffLocation,
                         double distance)
    : Ride(rideID, pickupLocation, dropoffLocation, distance) {
}

double PremiumRide::fare() const {
    return getDistance() * RATE_PER_MILE;
}

std::string PremiumRide::getRideType() const {
    return "Premium";
}