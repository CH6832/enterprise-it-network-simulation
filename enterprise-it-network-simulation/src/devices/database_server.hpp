#ifndef DATABASE_SERVER_HPP
#define DATABASE_SERVER_HPP

#include <string>
#include <spdlog/spdlog.h>

/**
 * @brief Simulated database server device.
 */
class DatabaseServer {
public:
    /**
     * @brief Constructor for DatabaseServer.
     * @param name Name of the server (default: "DatabaseServer").
     * @param ip IP address of the server.
     */
    DatabaseServer(const std::string& ip, const std::string& name = "DatabaseServer");

    /**
     * @brief Start the database server.
     */
    void startServer();

    /**
     * @brief Stop the database server.
     */
    void stopServer();

private:
    std::string client_name;
    std::string ip_address;
    bool serverRunning;
};

#endif // DATABASE_SERVER_HPP
