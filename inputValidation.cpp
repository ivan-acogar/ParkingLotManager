#include "inputValidation.hpp"
#include <iostream>

void clearConsole() {
	std::cout << "\033[2J\033[H";
}


void pressEnter() {
	std::cout << "\n\nPress enter to continue.";
	std::cin.get();
	clearConsole();
}


int readInteger() {
	int value{};

	std::cin >> value;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw std::runtime_error("Invalid Input.\n\n");
	}

	std::cin.ignore(10000, '\n');

	return value;
}


std::string readString() {
	std::string value{};

	std::getline(std::cin, value);

	if (std::cin.fail()) {
		std::cin.clear();
		throw std::runtime_error("Invalid input.\n\n");
	}

	if (value.empty()) {
		throw std::runtime_error("Input cannot be empty.\n\n");
	}

	return value;
}


void validPlateFormat(const std::string& plateNumber) {
	if (plateNumber.length() != 9) {
		throw std::runtime_error("The plate number must be 9 characters long.\n\n");
	}
	for (int i = 0; i < 3; ++i) {
		if (!std::isalpha(plateNumber[i])) {
			throw std::runtime_error("Invalid format.\n\n");
		}
	}
	if (plateNumber[3] != '-') {
		throw std::runtime_error("Invalid format.\n\n");
	}
	for (int i = 4; i < 7; ++i) {
		if (!std::isdigit(plateNumber[i])) {
			throw std::runtime_error("Invalid format.\n\n");
		}
	}
	if (plateNumber[7] != '-') {
		throw std::runtime_error("Invalid format.\n\n");
	}
	else if (!std::isalpha(plateNumber[8])) {
		throw std::runtime_error("Invalid format.\n\n");
	}
}


std::string convertToUppercasePlateNumber(std::string& plateNumber) {
	for (size_t i = 0; i < 9; ++i) {
		plateNumber[i] = std::toupper(plateNumber[i]);
	}
	return plateNumber;
}