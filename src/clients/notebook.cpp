#include "client_base.h"
#include <iostream>

/**
 * @class NotebookClient
 * @brief A concrete implementation of a VPN client for notebook devices.
 * 
 * This class implements the connect and disconnect functionality
 * specific to a notebook client in the VPN simulation.
 */
class NotebookClient : public ClientBase {
public:
    /**
     * @brief Constructor that initializes the notebook client with a name.
     * @param name The name of the notebook client.
     */
    NotebookClient(const std::string& name) : ClientBase(name) {}

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
