# Ride Sharing System

This project implements a class-based ride sharing system in **C++** and **Smalltalk (Pharo 13)**. It demonstrates three core object-oriented programming principles: encapsulation, inheritance, and polymorphism.

## Project Structure

- `cpp/` - C++ implementation
- `smalltalk/` - Smalltalk implementation
- `screenshots/` - Code and sample output screenshots

## Ride Types

The system supports three types of rides:

- **Standard Ride** - $2.00 per mile
- **Premium Ride** - $3.50 per mile
- **Shared Ride** - $1.50 per mile

All ride types inherit from the common `Ride` class and provide their own fare calculation.

## Object-Oriented Concepts

### Encapsulation

Ride, Driver, and Rider data are maintained within their respective classes and accessed or modified through defined methods. For example, a driver's assigned rides are managed through the Driver class rather than being modified directly.

### Inheritance

`StandardRide`, `PremiumRide`, and `SharedRide` inherit common ride information and behavior from the `Ride` class. Each specialized ride class provides behavior specific to its ride type.

### Polymorphism

Different ride objects are stored in a common collection. The same `fare()` operation is invoked on each object, while the appropriate fare calculation is selected according to the actual ride type.

For example:

- Standard Ride: 5 miles -> $10.00
- Premium Ride: 8 miles -> $28.00
- Shared Ride: 10 miles -> $15.00

In C++, this behavior is implemented using virtual methods. In Smalltalk, it is achieved through dynamic message dispatch.

## C++ Implementation

The C++ version uses a base `Ride` class with derived ride classes and stores different ride objects through base-class pointers.

To compile from the project root:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic cpp/*.cpp -o ride_sharing