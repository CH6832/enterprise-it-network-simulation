#include "client_base.h"
#include <iostream>

/**
 * @class SmartphoneClient
 * @brief A concrete implementation of a VPN client for smartphone devices.
 * 
 * This class implements the connect and disconnect functionality
 * specific to a smartphone client in the VPN simulation.
 */
class SmartphoneClient : public ClientBase {
public:
    /**
     * @brief Constructor that initializes the smartphone client with a name.
     * @param name The name of the smartphone client.
     */
    SmartphoneClient(const std::string& name) : ClientBase(name) {}

    /**
     * @brief Connect to the VPN.
     * Outputs a message indicating the connection status.
     */
    void connect() override {
        std::cout << getName() << " connected to the VPN." << std::endl;
    }

    /**
     * @brief Disconnect from the VPN.
     * Outputs a message indicating the disconnection status.
     */
    void disconnect() override {
        std::cout << getName() << " disconnected from the VPN." << std::endl;
    }

protected:
    /**
     * @brief Getter for the client name.
     * @return The name of the client.
     */
    std::string getName() const {
        return name_;
    }
};
