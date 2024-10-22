#ifndef VPNSERVER_HPP
#define VPNSERVER_HPP

#include "Device.hpp"
#include <string>

/**
 * @class VpnServer
 * @brief Represents a Virtual Private Network (VPN) server device.
 *
 * The VpnServer class inherits from the base class Device and provides
 * functionality specific to a VPN server, such as starting the server,
 * stopping the server, configuring encryption protocols, and managing
 * authentication and network interfaces.
 */
class VpnServer : public Device {
public:
    /**
     * @brief Constructor for the VpnServer class.
     * 
     * Initializes the VPN server with the given name.
     * 
     * @param name The name of the VPN server.
     */
    VpnServer(const std::string& name);

    /**
     * @brief Starts the VPN server.
     * 
     * This method handles the initialization of encryption protocols,
     * network interface binding, and the authentication system. It
     * also checks if the VPN server is already running to avoid
     * restarting an active server.
     */
    void start() override;

    /**
     * @brief Stops the VPN server.
     * 
     * This method handles the proper shutdown of the VPN server, including
     * closing active connections, cleaning up resources, and clearing
     * authentication tokens.
     */
    void stop() override;

    /**
     * @brief Destructor for the VpnServer class.
     * 
     * Ensures that the server is stopped when the VpnServer object is
     * destroyed, preventing resource leaks.
     */
    ~VpnServer() override;

private:
    bool isRunning;  ///< Indicates if the VPN server is currently running.

    /**
     * @brief Configures the encryption protocols for the VPN server.
     * 
     * This method simulates the configuration of encryption protocols
     * such as IPsec, OpenVPN, or WireGuard.
     */
    void configureEncryption();

    /**
     * @brief Checks and binds to a network interface for the VPN service.
     * 
     * Simulates binding the VPN server to a network interface for
     * handling network traffic.
     * 
     * @return True if the network interface was successfully bound, false otherwise.
     */
    bool checkNetworkInterface();

    /**
     * @brief Initializes the authentication system for the VPN server.
     * 
     * Simulates setting up user authentication mechanisms such as certificates,
     * username/password, or tokens.
     * 
     * @return True if authentication is successfully initialized, false otherwise.
     */
    bool initializeAuthentication();

    /**
     * @brief Cleans up active VPN connections.
     * 
     * This method simulates the closing of active connections during
     * the shutdown of the VPN server.
     */
    void cleanupConnections();

    /**
     * @brief Clears authentication tokens and sessions.
     * 
     * This method handles the removal of authentication data when the
     * VPN server is stopped.
     */
    void clearAuthentication();
};

#endif // VPNSERVER_HPP
