#include <iostream>
using namespace std;

// Strategy Interface
class DriveStrategy {
public:
   virtual void drive() const = 0;
   virtual ~DriveStrategy() = default;
};

// Concrete Strategies
class NormalDrive : public DriveStrategy {
public:
   void drive() const override {
      cout << "Normal driving mode." << endl;
   }
};

class SportsDrive : public DriveStrategy {
public:
   void drive() const override {
      cout << "Sports driving mode!" << endl;
   }
};

class OffRoadDrive : public DriveStrategy {
public:
   void drive() const override {
      cout << "Off-road driving mode!" << endl;
   }
};

// Context Class
class Vehicle {
protected:
   DriveStrategy* driveStrategy;
public:
   Vehicle(DriveStrategy* strategy) : driveStrategy(strategy) {}

   void drive() const {
      driveStrategy->drive();
   }
};

// Different Vehicles
class Car : public Vehicle {
public:
   Car() : Vehicle(new NormalDrive()) {}
};

class SportsCar : public Vehicle {
public:
   SportsCar() : Vehicle(new SportsDrive()) {}
};

class OffRoadVehicle : public Vehicle {
public:
   OffRoadVehicle() : Vehicle(new OffRoadDrive()) {}
};

// Main
int main() {
   Car car;
   car.drive(); // Output: Normal driving mode.

   SportsCar sportsCar;
   sportsCar.drive(); // Output: Sports driving mode!

   OffRoadVehicle offRoad;
   offRoad.drive(); // Output: Off-road driving mode!

   return 0;
}
