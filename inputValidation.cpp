#include "inputValidation.hpp"

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

void validPlateFormat(std::string plate) {
	if (plate.length() != 9) {
		throw std::runtime_error("The plate number must be 9 characters long.\n\n");
	}
	for (int i = 0; i < 3; ++i) {
		if (!std::isalpha(plate[i])) {
			throw std::runtime_error("Invalid format.\n\n");
		}
	}
	if (plate[3] != '-') {
		throw std::runtime_error("Invalid format.\n\n");
	}
	for (int i = 4; i < 7; ++i) {
		if (!std::isdigit(plate[i])) {
			throw std::runtime_error("Invalid format.\n\n");
		}
	}
	if (plate[7] != '-') {
		throw std::runtime_error("Invalid format.\n\n");
	}
	else if (!std::isalpha(plate[8])) {
		throw std::runtime_error("Invalid format.\n\n");
	}
}

std::string convertToUppercasePlateNumber(std::string plate) {
	for (size_t i = 0; i < 9; ++i) {
		plate[i] = std::toupper(plate[i]);
	}
	return plate;
}