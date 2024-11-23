#ifndef SWITCH_DEVICE_HPP
#define SWITCH_DEVICE_HPP

#include <string>

/**
 * @brief Simulates a network switch device.
 */
class SwitchDevice {
public:
    SwitchDevice(const std::string& deviceName);
    ~SwitchDevice();

    /**
     * @brief Simulates handling network traffic.
     * @param source Source of the traffic.
     * @param destination Destination of the traffic.
     */
    void handleTraffic(const std::string& source, const std::string& destination);

private:
    std::string name; /**< Name of the switch device */
};

#endif // SWITCH_DEVICE_HPP
