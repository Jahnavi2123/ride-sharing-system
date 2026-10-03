#ifndef STANDARD_RIDE_H
#define STANDARD_RIDE_H

#include "Ride.h"

class StandardRide : public Ride {
private:
    static constexpr double RATE_PER_MILE = 2.00;

public:
    StandardRide(const std::string& rideID,
                 const std::string& pickupLocation,
                 const std::string& dropoffLocation,
                 double distance);

    double fare() const override;
    std::string getRideType() const override;
};

#endif