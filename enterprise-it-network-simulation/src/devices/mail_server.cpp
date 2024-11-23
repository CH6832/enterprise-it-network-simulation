#include "mail_server.hpp"

MailServer::MailServer(const std::string& ip, const std::string& name)
    : client_name(name), ip_address(ip), serverRunning(false) {
    spdlog::info("{} created with IP: {}", client_name, ip);
}

void MailServer::startServer() {
    if (serverRunning) {
        spdlog::warn("{} mail server is already running.", client_name);
        return;
    }
    spdlog::info("{} is starting the mail server...", client_name);
    serverRunning = true;
    spdlog::info("{} mail server started.", client_name);
}

void MailServer::stopServer() {
    if (!serverRunning) {
        spdlog::warn("{} mail server is already stopped.", client_name);
        return;
    }
    spdlog::info("{} is stopping the mail server...", client_name);
    serverRunning = false;
    spdlog::info("{} mail server stopped.", client_name);
}
