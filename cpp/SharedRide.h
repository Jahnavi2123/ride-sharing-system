#ifndef SHARED_RIDE_H
#define SHARED_RIDE_H

#include "Ride.h"

class SharedRide : public Ride {
private:
    static constexpr double RATE_PER_MILE = 1.50;

public:
    SharedRide(const std::string& rideID,
               const std::string& pickupLocation,
               const std::string& dropoffLocation,
               double distance);

    double fare() const override;
    std::string getRideType() const override;
};

#endif