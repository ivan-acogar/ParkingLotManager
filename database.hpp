#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <pqxx/pqxx>
#include <string>

class Database {
private:
    pqxx::connection connection;

public:
    Database(const std::string& connectionString);

    void insertVehicle(
        const std::string& plateNumber,
        const std::string& ownerName,
        int entryHour
    );
};

#endif