#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP
#include "vehicle.hpp"
#include "parkingLot.hpp"
#include <string>
#include <iostream>
#include <exception>

void clearConsole();
void pressEnter();
int readInteger();
std::string readString();
void validPlateFormat(std::string plate);	
std::string convertToUppercasePlateNumber(std::string plate);

#endif 