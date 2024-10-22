#include "DatabaseServer.h"  // Include the header for the base Device class
#include <iostream>          // Include for input-output stream operations
#include <stdexcept>         // Include for standard exception handling

/**
 * @class DatabaseServer
 * @brief Represents a database server device that can be started and stopped.
 *
 * The DatabaseServer class inherits from the Device class and implements
 * specific functionality for database operations, such as starting the server,
 * stopping the server, and querying the database.
 */
DatabaseServer::DatabaseServer(const std::string& name) 
    : Device(name), isRunning(false) { // Initialize the state to not running
    // Constructor initializes the DatabaseServer with a name and sets its state
}

/**
 * @brief Starts the database server device.
 * 
 * This method outputs a message indicating that the database server is starting
 * and invokes the queryDatabase method to simulate querying the database.
 *
 * @throws std::runtime_error If the server cannot start due to some issue.
 */
void DatabaseServer::start() {
    if (isRunning) {
        std::cout << "Database server: " << name_ << " is already running." << std::endl;
        return;  // Prevent starting the server if it's already running
    }

    try {
        std::cout << "Starting database server: " << name_ << std::endl;
        
        // Simulate successful connection to the database
        if (!connectToDatabase()) {
            throw std::runtime_error("Failed to connect to the database.");
        }

        isRunning = true;  // Set state to running
        queryDatabase();    // Simulate a database query upon starting the server
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;  // Log the error
    }
}

/**
 * @brief Stops the database server device.
 * 
 * This method outputs a message indicating that the database server is stopping.
 * It also sets the running state to false.
 */
void DatabaseServer::stop() {
    if (!isRunning) {
        std::cout << "Database server: " << name_ << " is not running." << std::endl;
        return;  // Prevent stopping the server if it's not running
    }

    std::cout << "Stopping database server: " << name_ << std::endl;
    isRunning = false;  // Set state to not running
}

/**
 * @brief Simulates querying the database.
 * 
 * This method outputs a message indicating that a database query is being performed.
 * 
 * @throws std::runtime_error If the database query fails.
 */
void DatabaseServer::queryDatabase() {
    if (!isRunning) {
        throw std::runtime_error("Cannot query database: server is not running.");
    }
    
    std::cout << "Querying database..." << std::endl;
}

/**
 * @brief Simulates connecting to the database.
 * 
 * This method simulates a connection to the database and returns true if successful.
 * In a real-world application, this would involve actual connection logic.
 *
 * @return True if the connection is successful, otherwise false.
 */
bool DatabaseServer::connectToDatabase() {
    // Simulate a successful database connection
    return true;  // For now, assume the connection is always successful
}

/**
 * @brief Destructor for DatabaseServer class.
 * 
 * This method is called when a DatabaseServer object is destroyed. It ensures that
 * the server is stopped properly and cleans up any resources if necessary.
 */
DatabaseServer::~DatabaseServer() {
    if (isRunning) {
        stop();  // Ensure the server is stopped upon destruction
    }
}
