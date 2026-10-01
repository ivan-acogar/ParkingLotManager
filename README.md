# Parking Lot Manager

C++20 console app that manages parking lot entries, exits and payments with persistent PostgreSQL storage.

![Parking Lot Manager demo](docs/demo.gif)

## Features
- Register vehicles with validated license plates (ABC-123-A)
- Entry/exit timestamps generated server-side by PostgreSQL (UTC)
- Billing with partial hours rounded up
- Payment history stored across runs
- Capacity limit and duplicate-plate prevention

## Tech Stack
C++20 · PostgreSQL (Neon) · libpqxx · MSYS2 g++ · Git

## Neon PostgreSQL database
| Neon Vehicles table | Neon Payments table |
|---|---|
| ![Vehicles](docs/vehicles-neon.png) | ![Payments](docs/payments-neon.png) |

## Console screenshots
| Vehicle entry | Vehicle exit and payment |
|---|---|
| ![Entry](docs/entry.png) | ![Exit](docs/exit.png) |

| Parked vehicles | Payment history |
|---|---|
| ![List](docs/list.png) | ![Payments](docs/payments-console.png) |

## Quick Start
1. Install the requirements (see below)
2. Set the `NEON_DB_URL` environment variable with your database connection string
3. Create the tables by running `schema.sql` on your database
4. Build and run

From the MSYS2 UCRT64 terminal, in the project folder:
```bash
export NEON_DB_URL="postgresql://user:password@host/dbname?sslmode=require"
psql "$NEON_DB_URL" -f schema.sql
mkdir -p bin
g++ -std=c++20 -Wall -Wextra main.cpp database.cpp inputValidation.cpp parkingLot.cpp vehicle.cpp -lpqxx -lpq -o bin/ParkingLotManager.exe
./bin/ParkingLotManager.exe
```
`export` only lasts for the current terminal. To save the variable permanently, run `setx NEON_DB_URL "<connection-string>"` in PowerShell and open a new terminal.

In VS Code you can also build with **Ctrl+Shift+B**, which runs the included build task.

### Requirements
- **Windows 10/11**: the code reads the connection string with `_dupenv_s`, which is Windows-only
- **[MSYS2](https://www.msys2.org/)** using the **UCRT64** environment
- **g++ with C++20 support** (tested with GCC 16.1): `mingw-w64-ucrt-x86_64-gcc`
- **libpqxx 7.10+**: `mingw-w64-ucrt-x86_64-libpqxx`
- **libpq and psql** (PostgreSQL client): `mingw-w64-ucrt-x86_64-postgresql`
- **A PostgreSQL database**: a free [Neon](https://neon.tech/) account works

Install all packages from the MSYS2 UCRT64 terminal:
```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-libpqxx mingw-w64-ucrt-x86_64-postgresql
```
Make sure `C:\msys64\ucrt64\bin` is in your `PATH` so the `.exe` can find the DLLs at runtime.

## How It Works
### Architecture
- `ParkingLot`: capacity, searches, exits
- `Vehicle`: vehicle data
- `Database`: queries and transactions
- `inputValidation`: menu and plate validation

### Database Design
- `vehicles`: cars currently parked
- `payments`: completed transactions

Exiting a vehicle inserts the payment and deletes the vehicle in **one transaction**.

## Technical Highlights
- Parameterized queries to prevent SQL injection
- Credentials loaded from an environment variable
- Server-side timestamps (no dependence on local clock)
- Exception handling for input, config and database errors
