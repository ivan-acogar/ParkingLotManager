#include "parkingLot.hpp"
#include "database.hpp"
#include <pqxx/pqxx>
#include <cstdlib>
#include <iostream>
#include <string>

static void menuInputValidation(int menuOption) {
    if (menuOption < 1 || menuOption > 5) {
        throw std::runtime_error("Value is out of range.\n\n");
    }
}

int main()
{
    char* dbUrl = nullptr;
    size_t length = 0;

    _dupenv_s(&dbUrl, &length, "NEON_DB_URL");

    if (dbUrl == nullptr) {
        throw std::runtime_error("NEON_DB_URL environment variable not found.");
    }

    Database database(dbUrl);

    free(dbUrl);

    ParkingLot parkingLot(database);

    parkingLot.loadDatabaseData();



    std::cout << "Current time: ";

    bool loop{ true };
    while (loop == true) {
        std::cout << "--- Parking Lot Menu ---\n";
        std::cout << "1) Enter vehicle.\n";
        std::cout << "2) Exit vehicle.\n";
        std::cout << "3) Search vehicle.\n";
        std::cout << "4) Parked vehicles.\n";
        std::cout << "5) Exit program.\n\n";

        int menuOption{};
           try {
                std::cout << "Enter an option: ";
                menuOption = readInteger();
                menuInputValidation(menuOption);
           }
           catch (std::exception& e) {
               clearConsole();
               std::cout << "Error: " << e.what();
           }

        switch (menuOption) {
        case 1:
            clearConsole();
            parkingLot.capacityCheck();
            break;


        case 2:
            clearConsole();
            parkingLot.removeVehicle();
            break;

        case 3:
            clearConsole();
            parkingLot.searchVehicle();
            break;

        case 4:
            clearConsole();
            parkingLot.parkedVehicles();
            pressEnter();
            break;
            
        case 5:
            clearConsole();
            loop = false;
            std::cout << "\n";
            break;
        }
    }
}
