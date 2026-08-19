#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include <string>
#include <iostream>
#include <chrono>

class Vehicle {
private:
	std::string plateNumber;
	std::string ownerName;
	int entryHour;
	std::chrono::system_clock::time_point entryTime;
public:
	Vehicle(std::string plateNumber, std::string ownerName, int entryHour);
	std::string getPlateNumber() const;
	void printData() const;
	int getHour() const;

};

#endif 