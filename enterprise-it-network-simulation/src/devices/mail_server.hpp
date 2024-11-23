#ifndef MAIL_SERVER_HPP
#define MAIL_SERVER_HPP

#include <string>
#include <spdlog/spdlog.h>

/**
 * @brief Simulated mail server device.
 */
class MailServer {
public:
    /**
     * @brief Constructor for MailServer.
     * @param name Name of the server (default: "MailServer").
     * @param ip IP address of the server.
     */
    MailServer(const std::string& ip, const std::string& name = "MailServer");

    /**
     * @brief Start the mail server.
     */
    void startServer();

    /**
     * @brief Stop the mail server.
     */
    void stopServer();

private:
    std::string client_name;
    std::string ip_address;
    bool serverRunning;
};

#endif // MAIL_SERVER_HPP
