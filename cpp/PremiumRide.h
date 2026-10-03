#ifndef PREMIUM_RIDE_H
#define PREMIUM_RIDE_H

#include "Ride.h"

class PremiumRide : public Ride {
private:
    static constexpr double RATE_PER_MILE = 3.50;

public:
    PremiumRide(const std::string& rideID,
                const std::string& pickupLocation,
                const std::string& dropoffLocation,
                double distance);

    double fare() const override;
    std::string getRideType() const override;
};

#endif