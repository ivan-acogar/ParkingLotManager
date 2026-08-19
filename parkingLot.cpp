#include "parkingLot.hpp"

ParkingLot::ParkingLot(Database& database)
	: database(database) {
}

void ParkingLot::enterVehicle() {
	std::cout << "Enter vehicle (Remaining capacity: " << 3 - vehicles.size() << ").\n\n";

	std::string plateNumber{};
	std::string ownerName{};
	int entryHour{};
	try {
		std::cout << "Enter plate number (format: ABC-123-A): ";
		plateNumber = plateNumberValidation();
		if (plateNumberAlreadyExists(plateNumber) == true) {
			throw std::runtime_error("This plate number already exists.\n\n");
		}

		std::cout << "Owner's name: ";
		ownerName = readString(); //basic input validation.

		std::cout << "Entry hour: "; //checks for the entry hour to be inside the range.
		entryHour = readInteger();
		hourValidation(entryHour);

		vehicles.push_back(Vehicle(plateNumber, ownerName, entryHour));

		clearConsole();
		std::cout << "Vehicle registered:\n";
		std::cout << "Plate Number: " << plateNumber << " || ";
		std::cout << "Owner's Name: " << ownerName << " || ";
		std::cout << "Entry Hour: " << entryHour;

		database.insertVehicle(
			plateNumber,
			ownerName,
			entryHour
		);

		pressEnter();
	}
		catch (std::exception& e) {
			clearConsole();
			std::cout << "Error: " << e.what();
		}
}

bool ParkingLot::plateNumberAlreadyExists(std::string plateNumber) {
	for (size_t i = 0; i < vehicles.size(); ++i) { //checks if this plate number already exists inside the vector.
		if (plateNumber == vehicles[i].getPlateNumber()) {
			return true;
		}
		else {
			return false;
		}
	}
}

void ParkingLot::hourValidation(int entryHour) {
	if (entryHour < 0 || entryHour >= 24) {
		throw std::runtime_error("The value must be between 0 and 23.\n\n");
	}
}

void ParkingLot::capacityCheck() {
	if (vehicles.size() >= 3) {
		clearConsole();
		std::cout << "The parking lot is full.\n\n";
	}
	else {
		enterVehicle();
	}
}

void ParkingLot::searchVehicle() {
	try {
		if (vehicles.size() == 0) {
			throw std::runtime_error("The parking lot is empty.\n\n");
		}

		std::cout << "Search a vehicle.\n";

		std::cout << "Enter plate number (format: ABC-123-A): ";

		std::string plateNumber = plateNumberValidation();

		if (plateNumberAlreadyExists(plateNumber) == false) {
			throw std::runtime_error("This plate number does not exist.\n\n");
		}

		for (size_t i = 0; i < vehicles.size(); ++i) {
			if (plateNumber == vehicles[i].getPlateNumber()) {
				clearConsole();
				std::cout << "Vehicle found.\n\n";
				vehicles[i].printData();
				pressEnter();
			}
		}
		std::cout << "\n";
	}
	catch (std::exception& e) {
		clearConsole();
		std::cout << "Error: " << e.what();
	}
}

std::string ParkingLot::plateNumberValidation() {
	std::string plateNumber{};
	plateNumber = readString(); //basic input validation.
	validPlateFormat(plateNumber); //checks the input format.
	plateNumber = convertToUppercasePlateNumber(plateNumber);
	return plateNumber;

}

void ParkingLot::removeVehicle() {
	try {

		if (vehicles.size() == 0) {
			throw std::runtime_error("The parking lot is empty.\n\n");
		}

		std::cout << "--- Remove vehicle menu ---\n";
		std::cout << "1) Search by plate number.\n";
		std::cout << "2) Remove by showing the existing vehicles list.\n\n";

		std::cout << "Enter option: ";
		int menuOption = readInteger();

		switch(menuOption){
			case 1: {
				clearConsole();
				std::cout << "Search a vehicle.\n";

				std::cout << "Enter plate number (format: ABC-123-A): ";

				std::string plateNumber = plateNumberValidation();

				if (plateNumberAlreadyExists(plateNumber) == false) {
					throw std::runtime_error("This plate number does not exist.\n\n");
				}

				for (size_t i = 0; i < vehicles.size(); ++i) {
					if (plateNumber == vehicles[i].getPlateNumber()) {
						clearConsole();
						std::cout << "Vehicle found.\n";
						std::cout << "Enter exit hour: ";
						int exitHour = readInteger();
						hourValidation(exitHour);
						int entryHour = vehicles[i].getHour();
						std::cout << "\nEntry hour: " << entryHour << "\n";
						int totalHours{};
						if (exitHour == entryHour) {
							std::cout << "Charge: $25 (minimun charge).";
						}
						else {
							if (exitHour > entryHour) {
								totalHours = exitHour - entryHour;
							}
							else {
								totalHours = (24 - entryHour) + exitHour;
							}
							int charge = totalHours * 25;
							std::cout << "Charge: " << charge << " (Vehicle stayed for " << totalHours <<  " hours).\n\n";
						}
						vehicles.erase(vehicles.begin() + i);
						pressEnter();
					}
				}
				
				break;

			}

			case 2: {
				clearConsole();
				parkedVehicles();

				std::cout << "Enter the vehicle number to remove: ";
				int menuOption = readInteger();
				if (menuOption < 1 || menuOption > vehicles.size()) {
					throw std::runtime_error("Input is out of range.\n\n");
				}
				else {
					clearConsole();
					std::cout << "Vehicle found.\n";
					std::cout << "Enter exit hour: ";
					int exitHour = readInteger();
					hourValidation(exitHour);
					int entryHour = vehicles[menuOption-1].getHour();
					std::cout << "\nEntry hour: " << entryHour << "\n";
					int totalHours{};
					if (exitHour == entryHour) {
						std::cout << "Charge: $25 (minimun charge).";
					}
					else {
						if (exitHour > entryHour) {
							totalHours = exitHour - entryHour;
						}
						else {
							totalHours = (24 - entryHour) + exitHour;
						}
						int charge = totalHours * 25;
						std::cout << "Charge: " << charge << " (Vehicle stayed for " << totalHours << " hours).\n\n";
					}
					size_t index = menuOption - 1;
					vehicles.erase(vehicles.begin() + index);
					pressEnter();
				}
				break;
			}

		}

	}

	catch (std::exception& e) {
		clearConsole();
		std::cout << "Error: " << e.what();
	}
}

void ParkingLot::parkedVehicles() {
	std::vector<Vehicle> vehiclesFromDatabase = database.getVehicles();

	if (vehiclesFromDatabase.size() == 0) {
		clearConsole();
		std::cout << "The parking lot is empty.\n\n";
	}
	else {
		clearConsole();

		for (size_t i = 0; i < vehiclesFromDatabase.size(); ++i) {
			std::cout << i + 1 << ") ";
			vehiclesFromDatabase[i].printData();
		}

		pressEnter();
	}
}