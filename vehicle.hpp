#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include <string>
#include <iostream>

class Vehicle {
private:
	std::string plateNumber;
	std::string ownerName;
	int entryHour;
public:
	Vehicle(std::string plateNumber, std::string ownerName, int entryHour);
	std::string getPlateNumber();
	void printData();
	int getHour() const;

};

#endif 