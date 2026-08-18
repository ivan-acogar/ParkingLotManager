#include "database.hpp"

Database::Database(const std::string& connectionString)
    : connection(connectionString) {
}

void Database::insertVehicle(
    const std::string& plateNumber,
    const std::string& ownerName,
    int entryHour
) {
    pqxx::work transaction(connection);

    transaction.exec(
        "INSERT INTO vehicles "
        "(plate_number, owner_name, entry_hour) "
        "VALUES ($1, $2, $3)",
        pqxx::params{
            plateNumber,
            ownerName,
            entryHour
        }
    );

    transaction.commit();
}