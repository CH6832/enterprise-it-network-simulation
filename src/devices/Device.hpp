#ifndef DEVICE_H
#define DEVICE_H

#include <string>  // Include for string handling

/**
 * @class Device
 * @brief Abstract base class representing a generic device.
 *
 * The Device class provides a common interface for all devices. It defines
 * virtual methods for starting and stopping the device, ensuring that derived
 * classes implement these functionalities.
 */
class Device {
public:
    /**
     * @brief Constructs a Device object with the specified name.
     *
     * Initializes the device with a given name.
     *
     * @param name The name of the device.
     */
    explicit Device(const std::string& name) : name_(name) {}

    /**
     * @brief Starts the device.
     *
     * This method should be implemented by derived classes to provide
     * specific starting behavior.
     */
    virtual void start() = 0;  // Pure virtual function

    /**
     * @brief Stops the device.
     *
     * This method should be implemented by derived classes to provide
     * specific stopping behavior.
     */
    virtual void stop() = 0;   // Pure virtual function

    /**
     * @brief Retrieves the name of the device.
     *
     * @return The name of the device.
     */
    std::string getName() const {
        return name_;
    }

    /**
     * @brief Virtual destructor for the Device class.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~Device() = default;

private:
    std::string name_;  // The name of the device
};

#endif // DEVICE_H
