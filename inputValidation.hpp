#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP
#include <string>

void clearConsole();
void pressEnter();

int readInteger();
std::string readString();

void validPlateFormat(const std::string& plateNumber);
std::string convertToUppercasePlateNumber(std::string& plateNumber);

#endif 