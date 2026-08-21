#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include <string>

class Vehicle {
private:
	std::string plateNumber;
	std::string entryTime;
public:
	Vehicle(std::string plateNumber, std::string entryTime);

	std::string getPlateNumber() const;
	void printData() const;
};

#endif 