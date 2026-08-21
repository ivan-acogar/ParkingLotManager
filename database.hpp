#ifndef DATABASE_HPP
#define DATABASE_HPP
#include "vehicle.hpp"
#include <vector>
#include <exception>
#include <pqxx/pqxx>
#include <string>

class Database {
private:
    pqxx::connection connection;

public:
    Database(const std::string& connectionString);
    std::vector<Vehicle> getVehicles();

    std::string insertVehicleAndReturnTime(const std::string& plateNumber);
    std::string eraseVehicleAndReturnTime(const std::string& plateNumber, const double amount);

    int calculateTimeDifference(const std::string& plateNumber);

    void printPayments();
    void clearPaymentsHistory();
    bool paymentsEmpty();
};

#endif