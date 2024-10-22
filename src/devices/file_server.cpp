#include "FileServer.h"  // Include the header for the base Device class
#include <iostream>      // Include for input-output stream operations
#include <fstream>       // Include for file stream operations
#include <stdexcept>     // Include for standard exception handling
#include <string>        // Include for std::string

/**
 * @class FileServer
 * @brief Represents a file server device that can be started and stopped.
 *
 * The FileServer class inherits from the Device class and implements
 * specific functionality for file operations, such as starting the server,
 * stopping the server, and accessing files.
 */
FileServer::FileServer(const std::string& name) 
    : Device(name), isRunning(false) { // Initialize the state to not running
    // Constructor initializes the FileServer with a name and sets its state
}

/**
 * @brief Starts the file server device.
 * 
 * This method outputs a message indicating that the file server is starting
 * and invokes the accessFile method to simulate accessing a file.
 *
 * @throws std::runtime_error If the server cannot start due to some issue.
 */
void FileServer::start() {
    if (isRunning) {
        logMessage("File server: " + name_ + " is already running.");
        return;  // Prevent starting the server if it's already running
    }

    try {
        logMessage("Starting file server: " + name_);

        // Simulate successful access to files
        if (!initializeFileAccess()) {
            throw std::runtime_error("Failed to initialize file access.");
        }

        isRunning = true;  // Set state to running
        accessFile();      // Access a file upon starting the server
    } catch (const std::runtime_error& e) {
        logMessage("Error: " + std::string(e.what()));  // Log the error
    }
}

/**
 * @brief Stops the file server device.
 * 
 * This method outputs a message indicating that the file server is stopping.
 * It also sets the running state to false.
 */
void FileServer::stop() {
    if (!isRunning) {
        logMessage("File server: " + name_ + " is not running.");
        return;  // Prevent stopping the server if it's not running
    }

    logMessage("Stopping file server: " + name_);
    isRunning = false;  // Set state to not running
}

/**
 * @brief Simulates accessing a file.
 * 
 * This method outputs a message indicating that a file access operation is being performed.
 * 
 * @throws std::runtime_error If the file access fails.
 */
void FileServer::accessFile() {
    if (!isRunning) {
        throw std::runtime_error("Cannot access file: server is not running.");
    }

    const std::string filePath = "example.txt";  // Path to the file to access
    std::ifstream file(filePath);  // Open the file for reading

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    logMessage("Accessing file: " + filePath);

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;  // Output the contents of the file
    }

    file.close();  // Close the file after accessing
}

/**
 * @brief Simulates initializing file access.
 * 
 * This method simulates setting up necessary resources for file access and returns true if successful.
 * In a real-world application, this could involve checking permissions or opening connections.
 *
 * @return True if initialization is successful, otherwise false.
 */
bool FileServer::initializeFileAccess() {
    // Simulate successful initialization for file access
    return true;  // For now, assume the initialization is always successful
}

/**
 * @brief Logs a message to the console and can be extended for file logging.
 * 
 * This method outputs a log message with a timestamp for better tracking.
 * 
 * @param message The message to log.
 */
void FileServer::logMessage(const std::string& message) {
    std::cout << "[LOG] " << message << std::endl;  // Print log message to the console
}

/**
 * @brief Destructor for FileServer class.
 * 
 * This method is called when a FileServer object is destroyed. It ensures that
 * the server is stopped properly and cleans up any resources if necessary.
 */
FileServer::~FileServer() {
    if (isRunning) {
        stop();  // Ensure the server is stopped upon destruction
    }
}
