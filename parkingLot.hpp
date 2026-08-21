#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP
#include "database.hpp"
#include "vehicle.hpp"
#include <vector>

class ParkingLot {
private:
	std::vector <Vehicle> vehicles;
	Database& database;
	int capacity;

	std::string plateNumberValidation();
	bool plateNumberAlreadyExists(const std::string& plateNumber);
	void capacityCheck();

public:
	ParkingLot(Database& database);

	void enterVehicle();
	void removeVehicle();

	void searchVehicle();
	void parkedVehicles();

	void loadDatabaseData();
};

#endif 