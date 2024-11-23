#ifndef WEB_SERVER_HPP
#define WEB_SERVER_HPP

#include <string>
#include <spdlog/spdlog.h>

/**
 * @brief Simulated web server device.
 */
class WebServer {
public:
    /**
     * @brief Constructor for WebServer.
     * @param name Name of the server (default: "WebServer").
     * @param ip IP address of the server.
     */
    WebServer(const std::string& ip, const std::string& name = "WebServer");

    /**
     * @brief Start the web server.
     */
    void startServer();

    /**
     * @brief Stop the web server.
     */
    void stopServer();

private:
    std::string client_name;
    std::string ip_address;
    bool serverRunning;
};

#endif // WEB_SERVER_HPP
