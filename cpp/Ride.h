#ifndef RIDE_H
#define RIDE_H

#include <string>

class Ride {
private:
    std::string rideID;
    std::string pickupLocation;
    std::string dropoffLocation;
    double distance;

public:
    Ride(const std::string& rideID,
         const std::string& pickupLocation,
         const std::string& dropoffLocation,
         double distance);

    virtual ~Ride() = default;

    virtual double fare() const = 0;
    virtual void rideDetails() const;

    std::string getRideID() const;
    std::string getPickupLocation() const;
    std::string getDropoffLocation() const;
    double getDistance() const;

    virtual std::string getRideType() const = 0;
};

#endif