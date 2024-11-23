#ifndef TCP_UDP_LIMITS_HPP
#define TCP_UDP_LIMITS_HPP

/**
 * @brief Manages TCP/UDP connection limits.
 */
class TcpUdpLimits {
public:
    TcpUdpLimits(int maxConnections);
    ~TcpUdpLimits();

    /**
     * @brief Registers a new connection.
     * @return True if successful, false if limit reached.
     */
    bool registerConnection();

    /**
     * @brief Removes an existing connection.
     */
    void deregisterConnection();

    /**
     * @brief Gets the number of active connections.
     * @return Active connection count.
     */
    int getActiveConnections() const;

private:
    int maxConnections; /**< Maximum allowed connections */
    int currentConnections; /**< Current active connections */
};

#endif // TCP_UDP_LIMITS_HPP
