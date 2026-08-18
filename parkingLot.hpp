#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP
#include "database.hpp"
#include "vehicle.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

class ParkingLot {
private:
	std::vector <Vehicle> vehicles;
	Database& database;
	int capacity;
public:
	ParkingLot(Database& database);
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