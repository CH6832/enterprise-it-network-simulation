#ifndef VPN_TUNNEL_HPP
#define VPN_TUNNEL_HPP

#include <iostream>
#include <string>
#include <vector>

/**
 * @class VpnTunnel
 * @brief Simulates a VPN tunnel for secure communication.
 */
class VpnTunnel {
public:
    /**
     * @brief Constructor for the VpnTunnel class.
     * 
     * Initializes a new instance of the VPN tunnel with a given name.
     * 
     * @param name The name of the VPN tunnel.
     */
    VpnTunnel(const std::string& name);

    /**
     * @brief Establishes the VPN tunnel.
     * 
     * Initiates the connection and sets up the tunnel.
     */
    void connect();

    /**
     * @brief Disconnects the VPN tunnel.
     * 
     * Terminates the connection and cleans up resources.
     */
    void disconnect();

    /**
     * @brief Sends data through the VPN tunnel.
     * 
     * @param data The data to be sent through the tunnel.
     */
    void sendData(const std::string& data);

    /**
     * @brief Receives data from the VPN tunnel.
     * 
     * @return The received data.
     */
    std::string receiveData();

private:
    std::string name_;                 ///< Name of the VPN tunnel.
    bool isConnected_;                 ///< State of the connection.
    std::vector<std::string> dataQueue_;  ///< Queue to simulate incoming/outgoing data.

    /**
     * @brief Simulates the encryption of data.
     * 
     * @param data The data to encrypt.
     * @return The encrypted data.
     */
    std::string encrypt(const std::string& data);

    /**
     * @brief Simulates the decryption of data.
     * 
     * @param data The data to decrypt.
     * @return The decrypted data.
     */
    std::string decrypt(const std::string& data);
};

#endif // VPN_TUNNEL_HPP
