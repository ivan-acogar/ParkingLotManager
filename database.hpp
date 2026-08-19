#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <vector>
#include "vehicle.hpp"
#include <pqxx/pqxx>
#include <string>

class Database {
private:
    pqxx::connection connection;

public:
    std::vector<Vehicle> getVehicles();
    Database(const std::string& connectionString);

    void insertVehicle(const std::string& plateNumber,const std::string& ownerName,int entryHour);
};

#endif