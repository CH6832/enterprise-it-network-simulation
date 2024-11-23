#ifndef ROUTER_DEVICE_HPP
#define ROUTER_DEVICE_HPP

#include <string>
#include <spdlog/spdlog.h>

/**
 * @brief Simulated network router device.
 */
class RouterDevice {
public:
    /**
     * @brief Constructor for RouterDevice.
     * @param name Name of the router (default: "Router").
     * @param ip IP address of the device.
     */
    RouterDevice(const std::string& ip, const std::string& name = "Router");

    /**
     * @brief Start routing functionality.
     */
    void startRouting();

    /**
     * @brief Stop routing functionality.
     */
    void stopRouting();

private:
    std::string client_name;
    std::string ip_address;
    bool routing;
};

#endif // ROUTER_DEVICE_HPP
