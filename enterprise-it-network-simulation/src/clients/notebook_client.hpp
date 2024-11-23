#ifndef NOTEBOOK_CLIENT_HPP
#define NOTEBOOK_CLIENT_HPP

#include <string>

class NotebookClient {
public:
    /**
     * @brief Constructor for NotebookClient.
     * @param ip IP address of the client.
     * @param name Name of the client (default: "NotebookClient").
     */
    NotebookClient(const std::string& ip, const std::string& name = "NotebookClient");

    /**
     * @brief Connect to the VPN.
     */
    void connect();

    /**
     * @brief Disconnect from the VPN.
     */
    void disconnect();

    /**
     * @brief Get the name of the client.
     * @return The name of the client.
     */
    std::string getClientName() const;

    /**
     * @brief Check if the client is currently connected to the VPN.
     * @return True if connected, false otherwise.
     */
    bool isConnected() const;

    /**
     * @brief Simulate a failure in the client's network connection.
     */
    void simulateFailure();

private:
    std::string client_name;   ///< Name of the client.
    std::string ip_address;    ///< IP address of the client.
    bool connected;            ///< Tracks whether the client is connected to the VPN.

    /**
     * @brief Simulate network latency.
     */
    void simulateNetworkLatency() const;

    /**
     * @brief Simulate a random connection failure.
     * @return True if the connection fails, otherwise false.
     */
    bool simulateRandomFailure() const;
};

#endif // NOTEBOOK_CLIENT_HPP
