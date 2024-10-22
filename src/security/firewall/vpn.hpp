#ifndef VPN_HPP
#define VPN_HPP

#include <iostream>
#include <string>

/**
 * @brief Simulates a Virtual Private Network (VPN) server.
 */
class Vpn {
private:
    std::string name_;      // Name of the VPN server
    bool isRunning;         // Status of the VPN server

public:
    /**
     * @brief Constructor for the Vpn class.
     * 
     * @param name The name of the VPN server.
     */
    Vpn(const std::string& name);

    /**
     * @brief Starts the VPN server.
     * 
     * Initializes the VPN server and establishes a connection.
     */
    void start();

    /**
     * @brief Stops the VPN server.
     * 
     * Terminates the VPN connection and stops the server.
     */
    void stop();

    /**
     * @brief Establishes a VPN connection.
     * 
     * Simulates the process of connecting to a VPN.
     */
    void establishConnection();

    /**
     * @brief Disconnects the VPN connection.
     * 
     * Simulates the process of disconnecting from a VPN.
     */
    void disconnect();
};

#endif // VPN_HPP
