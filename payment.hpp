#ifndef PAYMENT_HPP
#define PAYMENT_HPP
#include "database.hpp"
#include <string>

class Payment {
public:
	int id;
	std::string plateNumber;
	double amount;
	std::string exitTime;
private:
	Payment(int id, std::string plateNumber, double amount, std::string exitTime);
};

#endif