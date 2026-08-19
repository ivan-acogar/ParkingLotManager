#include "database.hpp"

Database::Database(const std::string& connectionString)
    : connection(connectionString) {
}

std::vector<Vehicle> Database::getVehicles() {
    pqxx::work transaction(connection);

    pqxx::result result = transaction.exec(
        "SELECT plate_number, owner_name, entry_hour FROM vehicles"
    );

    std::vector<Vehicle> vehicles;

    for (const auto& row : result) {
        vehicles.emplace_back(
            row["plate_number"].as<std::string>(),
            row["owner_name"].as<std::string>(),
            row["entry_hour"].as<int>()
        );
    }

    transaction.commit();

    return vehicles;
}

void Database::insertVehicle(const std::string& plateNumber, const std::string& ownerName, int entryHour) {

    pqxx::work transaction(connection);

    transaction.exec(
        "INSERT INTO vehicles (plate_number, owner_name, entry_hour) VALUES ($1, $2, $3)", pqxx::params{plateNumber, ownerName, entryHour});

    transaction.commit();
}

void Database::eraseVehicle(const std::string plateNumber) {
    pqxx::work transaction(connection);

    transaction.exec("DELETE FROM vehicles WHERE plate_number = $1", pqxx::params{ plateNumber });

    transaction.commit();
}