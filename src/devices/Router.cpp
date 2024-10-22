#include "Router.h"      // Include the header for the base Device class
#include <iostream>      // Include for input-output stream operations
#include <stdexcept>     // Include for exception handling

/**
 * @class Router
 * @brief Represents a router device that can be started and stopped.
 *
 * The Router class inherits from the Device class and implements specific
 * functionality for routing operations, such as starting and stopping the router.
 */

/**
 * @brief Constructs a Router object with the specified name.
 *
 * Initializes the router device with the given name.
 *
 * @param name The name of the router device.
 */
Router::Router(const std::string& name) : Device(name), isRunning(false) {}

/**
 * @brief Starts the router device.
 *
 * This method outputs a message indicating that the router is starting.
 * It also initializes the routing algorithms and connections.
 */
void Router::start() {
    if (isRunning) {
        std::cout << "Router: " << name_ << " is already running." << std::endl;
        return;  // Prevent starting the router if it's already running
    }

    std::cout << "Starting router: " << name_ << std::endl;
    
    // Initialize routing algorithms here
    // Simulate establishing network connections
    isRunning = true;  // Set state to running
}

/**
 * @brief Stops the router device.
 *
 * This method outputs a message indicating that the router is stopping.
 * It also cleans up any active connections and resources.
 */
void Router::stop() {
    if (!isRunning) {
        std::cout << "Router: " << name_ << " is not running." << std::endl;
        return;  // Prevent stopping the router if it's not running
    }

    std::cout << "Stopping router: " << name_ << std::endl;
    // Clean up routing algorithms and connections here
    isRunning = false;  // Set state to not running
}

/**
 * @brief Simulates routing a packet through the network.
 *
 * This method outputs a message indicating that a packet is being routed.
 *
 * @param packet The data being routed.
 * @throws std::runtime_error If the router is not started.
 */
void Router::routePacket(const std::string& packet) {
    if (!isRunning) {
        throw std::runtime_error("Router is not running. Please start the router before routing packets.");
    }
    
    std::cout << "Routing packet: " << packet << std::endl;
}

/**
 * @brief Destructor for the Router class.
 *
 * Ensures that any necessary cleanup is performed when the router object is destroyed.
 */
Router::~Router() {
    if (isRunning) {
        stop();  // Ensure the router is stopped upon destruction
    }
}
