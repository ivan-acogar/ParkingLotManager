#include "payment.hpp"

Payment::Payment(int id, std::string plateNumber, double amount, std::string exitTime)
	: id(id), plateNumber(plateNumber), amount(amount), exitTime(exitTime){ }

