#ifndef DRIVER_H
#define DRIVER_H

#include "Ride.h"
#include <memory>
#include <string>
#include <vector>

class Driver {
private:
    std::string driverID;
    std::string name;
    double rating;

    // Kept private to demonstrate encapsulation.
    std::vector<std::shared_ptr<Ride>> assignedRides;

public:
    Driver(const std::string& driverID,
           const std::string& name,
           double rating);

    void addRide(const std::shared_ptr<Ride>& ride);
    void getDriverInfo() const;
    void viewAssignedRides() const;
};

#endif