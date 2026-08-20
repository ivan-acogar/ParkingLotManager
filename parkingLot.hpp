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
	void loadDatabaseData();
	void enterVehicle();
	std::string plateNumberValidation();
	bool plateNumberAlreadyExists(std::string plateNumber);
	void capacityCheck();
	void removeVehicle();
	void searchVehicle();
	void parkedVehicles();
	
};

#endif 