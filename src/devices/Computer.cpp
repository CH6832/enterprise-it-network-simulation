#include "Device.h"  // Include the header for the base Device class
#include <iostream>  // Include for input-output stream operations

/**
 * @class Computer
 * @brief Represents a computer device that can be started and stopped.
 *
 * The Computer class inherits from the Device class, which provides
 * basic device functionality. This class implements the start and
 * stop methods specific to a computer device.
 */
class Computer : public Device {
public:
    /**
     * @brief Constructor for the Computer class.
     * 
     * Initializes a new instance of the Computer with the given name.
     * 
     * @param name The name of the computer device.
     */
    Computer(const std::string& name) : Device(name) {}

    /**
     * @brief Starts the computer device.
     * 
     * This method outputs a message indicating that the computer is starting.
     * It overrides the start method from the Device base class.
     */
    void start() override {
        std::cout << "Starting computer: " << name_ << std::endl;
    }

    /**
     * @brief Stops the computer device.
     * 
     * This method outputs a message indicating that the computer is stopping.
     * It overrides the stop method from the Device base class.
     */
    void stop() override {
        std::cout << "Stopping computer: " << name_ << std::endl;
    }
};
