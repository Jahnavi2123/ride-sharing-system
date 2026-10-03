#ifndef RIDER_H
#define RIDER_H

#include "Ride.h"
#include <memory>
#include <string>
#include <vector>

class Rider {
private:
    std::string riderID;
    std::string name;
    std::vector<std::shared_ptr<Ride>> requestedRides;

public:
    Rider(const std::string& riderID,
          const std::string& name);

    void requestRide(const std::shared_ptr<Ride>& ride);
    void getRiderInfo() const;
    void viewRides() const;
};

#endif