#include "vehicle.hpp"
#include <iostream>

Vehicle::Vehicle(std::string plateNumber, std::string entryTime)
	: plateNumber(plateNumber), entryTime(entryTime) {
}

std::string Vehicle::getPlateNumber() const{
	return plateNumber;
}

void Vehicle::printData() const {
	std::cout << "Plate Number: " << plateNumber << " || ";
	std::cout << "Entry Time: " << entryTime << "\n";
}
