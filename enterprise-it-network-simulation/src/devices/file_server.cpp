#include "file_server.hpp"

FileServer::FileServer(const std::string& ip, const std::string& name)
    : client_name(name), ip_address(ip), serviceRunning(false) {
    spdlog::info("{} created with IP: {}", client_name, ip);
}

void FileServer::startService() {
    if (serviceRunning) {
        spdlog::warn("{} service is already running.", client_name);
        return;
    }
    spdlog::info("{} is starting file sharing service...", client_name);
    serviceRunning = true;
    spdlog::info("{} file sharing service started.", client_name);
}

void FileServer::stopService() {
    if (!serviceRunning) {
        spdlog::warn("{} service is not running.", client_name);
        return;
    }
    spdlog::info("{} is stopping file sharing service...", client_name);
    serviceRunning = false;
    spdlog::info("{} file sharing service stopped.", client_name);
}
