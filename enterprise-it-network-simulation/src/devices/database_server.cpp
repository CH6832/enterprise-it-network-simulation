#include "database_server.hpp"

DatabaseServer::DatabaseServer(const std::string& ip, const std::string& name)
    : client_name(name), ip_address(ip), serverRunning(false) {
    spdlog::info("{} created with IP: {}", client_name, ip);
}

void DatabaseServer::startServer() {
    if (serverRunning) {
        spdlog::warn("{} database server is already running.", client_name);
        return;
    }
    spdlog::info("{} is starting the database server...", client_name);
    serverRunning = true;
    spdlog::info("{} database server started.", client_name);
}

void DatabaseServer::stopServer() {
    if (!serverRunning) {
        spdlog::warn("{} database server is already stopped.", client_name);
        return;
    }
    spdlog::info("{} is stopping the database server...", client_name);
    serverRunning = false;
    spdlog::info("{} database server stopped.", client_name);
}
