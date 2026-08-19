#include "vehicle.hpp"

Vehicle::Vehicle(std::string plateNumber, std::string ownerName, int entryHour)
	: plateNumber(plateNumber), ownerName(ownerName), entryHour(entryHour) {
}

std::string Vehicle::getPlateNumber() const{
	return plateNumber;
}

void Vehicle::printData() const {
	std::cout << "Plate Number: " << plateNumber << " || ";
	std::cout << "Owner's name: " << ownerName << " || ";
	std::cout << "Entry hour: " << entryHour << "\n";
}

int Vehicle::getHour() const {
	return entryHour;
}