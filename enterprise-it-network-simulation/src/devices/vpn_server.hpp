#ifndef VPN_SERVER_HPP
#define VPN_SERVER_HPP

#include <string>
#include <spdlog/spdlog.h>

/**
 * @brief Simulated VPN server device.
 */
class VPNServer {
public:
    /**
     * @brief Constructor for VPNServer.
     * @param name Name of the server (default: "VPNServer").
     * @param ip IP address of the server.
     */
    VPNServer(const std::string& ip, const std::string& name = "VPNServer");

    /**
     * @brief Start the VPN server.
     */
    void startServer();

    /**
     * @brief Stop the VPN server.
     */
    void stopServer();

private:
    std::string client_name;
    std::string ip_address;
    bool serverRunning;
};

#endif // VPN_SERVER_HPP
