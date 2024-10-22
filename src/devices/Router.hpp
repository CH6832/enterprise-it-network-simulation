#ifndef ROUTER_H
#define ROUTER_H

#include "Device.h"  // Include the base Device class header
#include <string>    // Include for string handling
#include <stdexcept> // Include for exception handling

/**
 * @class Router
 * @brief Represents a router device that can route packets.
 *
 * The Router class inherits from the Device class and implements specific
 * functionality for routing operations, such as starting, stopping,
 * and routing packets.
 */
class Router : public Device {
public:
    /**
     * @brief Constructs a Router object with the specified name.
     *
     * Initializes the router device with the given name.
     *
     * @param name The name of the router device.
     */
    Router(const std::string& name);

    /**
     * @brief Starts the router device.
     *
     * Outputs a message indicating that the router is starting.
     */
    void start() override;

    /**
     * @brief Stops the router device.
     *
     * Outputs a message indicating that the router is stopping.
     */
    void stop() override;

    /**
     * @brief Routes a packet through the network.
     *
     * Outputs a message indicating that a packet is being routed.
     *
     * @param packet The data being routed.
     *
     * @throws std::runtime_error If the router is not started.
     */
    void routePacket(const std::string& packet);

    /**
     * @brief Destructor for the Router class.
     *
     * Ensures that any necessary cleanup is performed when the router object is destroyed.
     */
    ~Router();

private:
    bool isRunning; // Indicates if the router is currently running
};

#endif // ROUTER_H
