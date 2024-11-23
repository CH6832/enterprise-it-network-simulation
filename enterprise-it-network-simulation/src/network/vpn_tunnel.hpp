#ifndef VPN_TUNNEL_HPP
#define VPN_TUNNEL_HPP

#include <string>
#include <spdlog/spdlog.h>
#include <stdexcept>
#include <chrono>
#include <thread>

/**
 * @brief A class to simulate a VPN tunnel.
 */
class VpnTunnel {
public:
    /**
     * @brief Constructor for VpnTunnel.
     * @param tunnelAddress The address of the VPN server to connect to.
     */
    explicit VpnTunnel(const std::string& tunnelAddress);

    /**
     * @brief Destructor for VpnTunnel.
     */
    ~VpnTunnel();

    /**
     * @brief Starts the VPN tunnel connection.
     * @throws std::runtime_error if the connection fails.
     */
    void startTunnel();

    /**
     * @brief Stops the VPN tunnel connection.
     */
    void stopTunnel();

    /**
     * @brief Checks if the VPN tunnel is active.
     * @return true if the VPN tunnel is active, false otherwise.
     */
    bool isTunnelActive() const;

private:
    std::string tunnelAddress;   ///< Address of the VPN server
    bool tunnelActive;           ///< Flag to indicate whether the tunnel is active
};

#endif // VPN_TUNNEL_HPP
