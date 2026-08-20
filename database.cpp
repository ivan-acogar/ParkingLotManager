#include "database.hpp"

Database::Database(const std::string& connectionString)
    : connection(connectionString) {
}

std::vector<Vehicle> Database::getVehicles() {
    pqxx::work transaction(connection);

    pqxx::result result = transaction.exec("SELECT plate_number, entry_time FROM vehicles");

    std::vector<Vehicle> vehicles;

    for (const auto& row : result) {
        vehicles.emplace_back(row["plate_number"].as<std::string>(), row["entry_time"].as<std::string>());
    }

    transaction.commit();

    return vehicles;
}

void Database::printPayments() {
    pqxx::work transaction(connection);

    pqxx::result result = transaction.exec("SELECT id, plate_number, amount, exit_time FROM payments");

    for (const auto& row : result) {
        std::cout << "ID: " << row["id"].as<int>() << " || Plate Number: " << row["plate_number"].as<std::string>() << " || Amount: " << row["amount"].as<double>() << " || Exit Time: " << row["exit_time"].as<std::string>() << "\n";
    }

    transaction.commit();
}

std::string Database::insertVehicleAndReturnTime(const std::string& plateNumber) {

    pqxx::work transaction(connection);

    pqxx::result result = transaction.exec(
        "INSERT INTO vehicles (plate_number, entry_time) VALUES ($1, CURRENT_TIMESTAMP) RETURNING entry_time", pqxx::params{plateNumber});

    std::string entryTime = result[0]["entry_time"].as<std::string>();

    transaction.commit();

    return entryTime;
}

std::string Database::eraseVehicleAndReturnTime(const std::string plateNumber, double amount) {

    pqxx::work transaction(connection);

    pqxx::result result = transaction.exec("INSERT INTO payments (plate_number, amount, exit_time) VALUES ($1, $2, CURRENT_TIMESTAMP) RETURNING exit_time", pqxx::params{ plateNumber, amount});

    transaction.exec("DELETE FROM vehicles WHERE plate_number = $1", pqxx::params{ plateNumber });

    std::string exitTime = result[0]["exit_time"].as<std::string>();

    transaction.commit();

    return exitTime;
}

double Database::calculateTimeDifference(std::string plateNumber) {
    pqxx::work transaction(connection);

    pqxx::result result = transaction.exec("SELECT EXTRACT(EPOCH FROM(CURRENT_TIMESTAMP - entry_time)) / 3600.0 FROM vehicles WHERE plate_number = $1", pqxx::params{ plateNumber });

    double hours = result[0][0].as<double>();

    transaction.commit();

    return hours;
}

std::string updatePaymentVector(const std::string ) {

}