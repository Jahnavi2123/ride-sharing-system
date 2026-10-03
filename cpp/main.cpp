#include "Driver.h"
#include "PremiumRide.h"
#include "Rider.h"
#include "SharedRide.h"
#include "StandardRide.h"

#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::cout << "====================================\n";
    std::cout << "       RIDE SHARING SYSTEM\n";
    std::cout << "====================================\n\n";

    // Create different ride subclasses.
    auto standardRide = std::make_shared<StandardRide>(
        "R101", "Downtown Atlanta", "Midtown Atlanta", 5.0);

    auto premiumRide = std::make_shared<PremiumRide>(
        "R102", "Midtown Atlanta", "Buckhead", 8.0);

    auto sharedRide = std::make_shared<SharedRide>(
        "R103", "Buckhead", "Downtown Atlanta", 10.0);

    // Store different ride types through the same base-class type.
    std::vector<std::shared_ptr<Ride>> rides = {
        standardRide,
        premiumRide,
        sharedRide
    };

    std::cout << "RIDE DETAILS\n";
    std::cout << "------------------------------------\n";

    for (const auto& ride : rides) {
        ride->rideDetails();
        std::cout << "------------------------------------\n";
    }

    // The same fare() call executes different subclass implementations.
    std::cout << "\nPOLYMORPHIC FARE CALCULATION\n";
    std::cout << "------------------------------------\n";

    for (const auto& ride : rides) {
        std::cout << ride->getRideType()
                  << " Ride (" << ride->getDistance() << " miles)"
                  << " -> $" << ride->fare() << '\n';
    }

    Driver driver("D101", "Alex", 4.9);
    driver.addRide(standardRide);
    driver.addRide(premiumRide);

    std::cout << "\n\nDRIVER INFORMATION\n";
    std::cout << "------------------------------------\n";
    driver.getDriverInfo();
    driver.viewAssignedRides();

    Rider rider("U101", "Jahnavi");
    rider.requestRide(standardRide);
    rider.requestRide(sharedRide);

    std::cout << "\n\nRIDER INFORMATION\n";
    std::cout << "------------------------------------\n";
    rider.getRiderInfo();
    rider.viewRides();

    std::cout << "\n====================================\n";
    std::cout << "          END OF DEMO\n";
    std::cout << "====================================\n";

    return 0;
}