#include "parkingLot.hpp"
#include "database.hpp"
#include <pqxx/pqxx>
#include <cstdlib>
#include <iostream>
#include <string>

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

    bool loop{ true };
    while (loop == true) {
        std::cout << "--- Parking Lot Menu ---\n";
        std::cout << "0) Exit program.\n";
        std::cout << "1) Enter vehicle.\n";
        std::cout << "2) Exit vehicle.\n";
        std::cout << "3) Search vehicle.\n";
        std::cout << "4) Show Parked vehicles.\n";
        std::cout << "5) Show Payments History.\n";
        std::cout << "6) Clear Payments History.\n\n";

        int menuOption{};
        try {
            std::cout << "Enter an option: ";
            menuOption = readInteger();

            switch (menuOption) {

            case 0:
                clearConsole();
                loop = false;
                std::cout << "Program terminated. \n";
                break;

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
                database.printPayments();
                pressEnter();
                break;

            case 6:
                clearConsole();
                database.clearPaymentsHistory();
                pressEnter();
                break;

            default:
                throw std::runtime_error("Invalid value.\n\n");
            }
        }

        catch (std::exception& e) {
            clearConsole();
            std::cout << "Error: " << e.what();
        }
    }
}
