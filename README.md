# Parking Lot Manager

A C++20 console application for managing parking lot operations with persistent cloud storage through PostgreSQL and Neon.

The project demonstrates object-oriented design, database integration, SQL transactions, input validation, exception handling, and separation of responsibilities across multiple C++ classes.

## Features

* Register vehicles using validated license plates
* Store entry and exit timestamps automatically
* Search for parked vehicles by license plate
* Display all currently parked vehicles
* Calculate billable hours and parking fees
* Save completed payments
* Display and clear payment history
* Prevent duplicate vehicle registrations
* Enforce a maximum parking capacity
* Preserve data between program executions

## Technologies

* C++20
* PostgreSQL
* Neon Serverless Postgres
* libpqxx
* STL containers
* Visual Studio 2026
* Git and GitHub

## Project Structure

```text
ParkingLotManager/
├── main.cpp
├── parkingLot.hpp
├── parkingLot.cpp
├── vehicle.hpp
├── vehicle.cpp
├── database.hpp
├── database.cpp
├── inputValidation.hpp
├── inputValidation.cpp
├── schema.sql
├── ParkingLotManager.slnx
└── README.md
```

### Main components

* `ParkingLot` manages parking operations, capacity, searches, and vehicle exits.
* `Vehicle` represents a parked vehicle and its entry information.
* `Database` manages PostgreSQL queries and transactions.
* `inputValidation` validates menu input and license plate formatting.
* `main` initializes the database connection and controls the application menu.

## Database Design

The application uses two PostgreSQL tables:

* `vehicles` stores vehicles currently inside the parking lot.
* `payments` stores completed parking transactions.

Vehicle removal and payment registration are performed in the same SQL transaction, helping maintain consistent data.

## Requirements

Before running the project, install:

* Visual Studio with Desktop development with C++
* C++20-compatible compiler
* Git
* vcpkg
* A PostgreSQL database or free Neon account
* libpqxx

Install libpqxx through vcpkg:

```powershell
vcpkg install libpqxx:x64-windows
vcpkg integrate install
```

## Database Setup

Create a PostgreSQL database and execute the following schema:

```sql
CREATE TABLE vehicles (
    plate_number VARCHAR(9) PRIMARY KEY,
    entry_time TIMESTAMPTZ NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE payments (
    id INTEGER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    plate_number VARCHAR(9) NOT NULL,
    amount NUMERIC(10, 2) NOT NULL,
    exit_time TIMESTAMPTZ NOT NULL DEFAULT CURRENT_TIMESTAMP
);
```

Save this SQL in a file named `schema.sql` in the project root.

## Environment Variable

The database connection string is loaded from an environment variable so credentials are never stored in the source code.

On Windows PowerShell:

```powershell
setx NEON_DB_URL "your_postgresql_connection_string"
```

Restart Visual Studio after creating the variable.

> Never commit your real database connection string or credentials to GitHub.

## Build and Run

1. Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/ParkingLotManager.git
```

2. Open `ParkingLotManager.slnx` in Visual Studio.

3. Select the `x64` configuration.

4. Build and run the project.

5. Use the console menu to manage vehicles and payments.

## Example Menu

```text
--- Parking Lot Menu ---
0) Exit program
1) Enter vehicle
2) Exit vehicle
3) Search vehicle
4) Show parked vehicles
5) Show payments history
6) Clear payments history
```

License plates use the following format:

```text
ABC-123-A
```

Lowercase input is automatically converted to uppercase.

## Technical Highlights

* Parameterized SQL queries help prevent SQL injection.
* PostgreSQL generates timestamps instead of relying on local computer time.
* Partial parking hours are rounded up for billing.
* SQL transactions keep related database operations together.
* Database credentials are protected through environment variables.
* Exceptions handle invalid input, missing configuration, and database failures.
* Header and source files keep interfaces separate from implementations.

## Future Improvements

* Add automated unit tests
* Add an optional SQLite mode for easier local demonstrations
* Add configurable parking capacity and hourly rates
* Improve database reconnection handling
* Create a graphical user interface
* Add administrator authentication
* Generate payment receipts

## Purpose

I developed this project to strengthen my understanding of C++, object-oriented programming, relational databases, SQL transactions, secure configuration, and maintainable software structure.
