#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <vector>
#include <chrono>
#include "vehicle.hpp"
#include "payment.hpp"
#include <pqxx/pqxx>
#include <string>

class Database {
private:
    pqxx::connection connection;

public:
    std::vector<Vehicle> getVehicles();

    void printPayments();

    void clearPaymentsHistory();

    bool paymentsEmpty();

    Database(const std::string& connectionString);

    std::string insertVehicleAndReturnTime(const std::string& plateNumber);

    std::string eraseVehicleAndReturnTime(const std::string plateNumber, double amount);

    double calculateTimeDifference(const std::string plateNumber);

};

#endif