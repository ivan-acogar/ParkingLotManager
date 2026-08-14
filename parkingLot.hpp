#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP
#include "vehicle.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

class ParkingLot {
private:
	std::vector <Vehicle> vehicles;
	int capacity;
public:
	void enterVehicle();
	std::string plateNumberValidation();
	bool plateNumberAlreadyExists(std::string plateNumber);
	void hourValidation(int entryHour);
	void capacityCheck();
	void removeVehicle();
	void searchVehicle();
	void parkedVehicles();
	
};

#endif 