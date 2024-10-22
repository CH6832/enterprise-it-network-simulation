#ifndef CLIENT_BASE_H
#define CLIENT_BASE_H

#include <string>

/**
 * @class ClientBase
 * @brief Base class for VPN clients in the simulation.
 * 
 * This class provides the basic interface for connecting and disconnecting
 * from a VPN. Derived classes must implement the connect and disconnect methods.
 */
class ClientBase {
public:
    /**
     * @brief Constructor that initializes the client with a name.
     * @param name The name of the client.
     */
    explicit ClientBase(const std::string& name) : name_(name) {}

    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~ClientBase() = default;

    /**
     * @brief Connect to the VPN.
     * Must be implemented by derived classes.
     */
    virtual void connect() = 0;

    /**
     * @brief Disconnect from the VPN.
     * Must be implemented by derived classes.
     */
    virtual void disconnect() = 0;

protected:
    std::string name_; ///< The name of the client.
};

#endif // CLIENT_BASE_H
