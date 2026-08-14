#include "parkingLot.hpp"
#include <iostream>
#include <string>

static void menuInputValidation(int menuOption) {
    if (menuOption < 1 || menuOption > 5) {
        throw std::runtime_error("Value is out of range.\n\n");
    }
}

int main()
{
    ParkingLot parkingLot;
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
                std::cout << "\nError: " << e.what();
           }

        switch (menuOption) {
        case 1:
            parkingLot.capacityCheck();
            break;


        case 2:
            parkingLot.removeVehicle();
            break;

        case 3:
            parkingLot.searchVehicle();
            break;

        case 4:
            parkingLot.parkedVehicles();
            break;
            
        case 5: 
            loop = false;
            std::cout << "\n";
            break;
        }
    }
}
