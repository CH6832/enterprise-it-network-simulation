#ifndef FIREWALL_DEVICE_HPP
#define FIREWALL_DEVICE_HPP

#include <string>
#include <spdlog/spdlog.h>

/**
 * @brief Simulated network firewall device.
 */
class FirewallDevice {
public:
    /**
     * @brief Constructor for FirewallDevice.
     * @param name Name of the firewall (default: "Firewall").
     * @param ip IP address of the device.
     */
    FirewallDevice(const std::string& ip, const std::string& name = "Firewall");

    /**
     * @brief Enable the firewall.
     */
    void enable();

    /**
     * @brief Disable the firewall.
     */
    void disable();

private:
    std::string client_name;
    std::string ip_address;
    bool enabled;
};

#endif // FIREWALL_DEVICE_HPP
