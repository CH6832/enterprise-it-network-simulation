#ifndef DATABASE_SERVER_H
#define DATABASE_SERVER_H

#include "Device.h"         // Include the header for the base Device class
#include <string>           // Include for using std::string
#include <stdexcept>        // Include for standard exception handling

/**
 * @class DatabaseServer
 * @brief Represents a database server device that can be started and stopped.
 *
 * The DatabaseServer class inherits from the Device class and implements
 * specific functionality for database operations, such as starting the server,
 * stopping the server, and querying the database.
 */
class DatabaseServer : public Device {
public:
    /**
     * @brief Constructor for the DatabaseServer class.
     * 
     * Initializes a new instance of the DatabaseServer with the given name.
     * The initial state is set to not running.
     * 
     * @param name The name of the database server device.
     */
    DatabaseServer(const std::string& name);

    /**
     * @brief Destructor for the DatabaseServer class.
     * 
     * Ensures that the server is stopped properly upon destruction.
     */
    ~DatabaseServer();

    /**
     * @brief Starts the database server device.
     * 
     * Outputs a message indicating that the database server is starting
     * and invokes the queryDatabase method to simulate querying the database.
     *
     * @throws std::runtime_error If the server cannot start due to some issue.
     */
    void start() override;  // Override the start method from the base class

    /**
     * @brief Stops the database server device.
     * 
     * Outputs a message indicating that the database server is stopping
     * and sets the running state to false.
     */
    void stop() override;   // Override the stop method from the base class

private:
    /**
     * @brief Simulates querying the database.
     * 
     * Outputs a message indicating that a database query is being performed.
     * 
     * @throws std::runtime_error If the database query fails.
     */
    void queryDatabase();  

    /**
     * @brief Simulates connecting to the database.
     * 
     * This method simulates a connection to the database and returns true
     * if successful. In a real-world application, this would involve actual
     * connection logic.
     *
     * @return True if the connection is successful, otherwise false.
     */
    bool connectToDatabase();  

    bool isRunning;  // Tracks whether the database server is currently running
};

#endif // DATABASE_SERVER_H
