#include "vehicle.hpp"

Vehicle::Vehicle(std::string plateNumber, std::string ownerName, int entryHour)
	: plateNumber(plateNumber), ownerName(ownerName), entryHour(entryHour) {
}

std::string Vehicle::getPlateNumber() {
	return plateNumber;
}

void Vehicle::printData() {
	std::cout << "Plate Number: " << plateNumber << " || ";
	std::cout << "Owner's name: " << ownerName << " || ";
	std::cout << "Entry hour: " << entryHour << "\n";
}

int Vehicle::getHour() const {
	return entryHour;
}