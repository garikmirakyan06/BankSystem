# Bank System Management

A single-file C++ console application that simulates basic bank management operations like creating accounts, performing transactions, viewing balances, and more. Built using Object-Oriented Programming and JSON file storage via [`nlohmann/json`](https://github.com/nlohmann/json).

## Operations

1. Create an Account
2. Update information of existing account
3. For transactions
4. Check the details of existing account
5. Removing existing account
6. View customer's list
7. Exit

## Data Handling

The application uses two layers for handling user account data:

1. **In-Memory Storage**  
   All user accounts are stored in memory using an `std::unordered_map<std::string, Account>`, where the key is the account name. This allows for fast operations during runtime.

   ### Why `unordered_map`?

   - Provides fast average-case time complexity for insertions, deletions, and lookups.
   - Account operations (like checking existence, updating balance, or deleting) can be done in **constant average time**.

   ### Time Complexities

   | Operation         | Complexity |
   |------------------|------------|
   | Insert account    | O(1) avg   |
   | Authenticate user | O(1) avg   |
   | Update account    | O(1) avg   |
   | Delete account    | O(1) avg   |
   | View customer list| O(n)       |

2. **Persistent Storage**  
   All user data is saved and loaded from a JSON file named `data.json`, located in the `data/` folder. The data is written to this file after any account creation, update, or deletion to ensure persistence between sessions.

   - The file acts as a simple database.
   - Data is serialized and deserialized using the `nlohmann/json` library.

## Installation and Setup

This project uses **CMake** for building and supports both local and containerized development.

### Building Locally:

To build the project locally you can just run script `build.sh` that in directory `scripts` 
   
### Docker:
there is also `Dockerfile` wich will install all necessary dependencies in new environment 
If you prefer using Docker you can run `./scripts/docker_run.sh`. You can also run `docker_install.sh` if you dont have it.


