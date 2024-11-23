#ifndef FILE_SERVER_HPP
#define FILE_SERVER_HPP

#include <string>
#include <spdlog/spdlog.h>
#include <stdexcept>

/**
 * @brief Simulated file server device.
 */
class FileServer {
public:
    /**
     * @brief Constructor for FileServer.
     * @param name Name of the server (default: "FileServer").
     * @param ip IP address of the device.
     */
    FileServer(const std::string& ip, const std::string& name = "FileServer");

    /**
     * @brief Start file sharing service.
     */
    void startService();

    /**
     * @brief Stop file sharing service.
     */
    void stopService();

private:
    std::string client_name;
    std::string ip_address;
    bool serviceRunning;
};

#endif // FILE_SERVER_HPP
