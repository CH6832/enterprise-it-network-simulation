#ifndef COMPUTER_DEVICE_HPP
#define COMPUTER_DEVICE_HPP

#include <string>
#include <spdlog/spdlog.h>
#include <stdexcept>

/**
 * @brief Simulated network computer device.
 */
class ComputerDevice {
public:
    /**
     * @brief Constructor for ComputerDevice.
     * @param name Name of the computer device (default: "Computer").
     * @param ip IP address of the device.
     */
    ComputerDevice(const std::string& ip, const std::string& name = "Computer");

    /**
     * @brief Connect to the network.
     */
    void connect();

    /**
     * @brief Disconnect from the network.
     */
    void disconnect();

    /**
     * @brief Check if the computer is currently connected to the network.
     * @return True if connected, false otherwise.
     */
    bool isConnected() const;

private:
    std::string client_name;
    std::string ip_address;
    bool connected;
};

#endif // COMPUTER_DEVICE_HPP
