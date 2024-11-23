#include "web_server.hpp"

WebServer::WebServer(const std::string& ip, const std::string& name)
    : client_name(name), ip_address(ip), serverRunning(false) {
    spdlog::info("{} created with IP: {}", client_name, ip);
}

void WebServer::startServer() {
    if (serverRunning) {
        spdlog::warn("{} web server is already running.", client_name);
        return;
    }
    spdlog::info("{} is starting the web server...", client_name);
    serverRunning = true;
    spdlog::info("{} web server started.", client_name);
}

void WebServer::stopServer() {
    if (!serverRunning) {
        spdlog::warn("{} web server is already stopped.", client_name);
        return;
    }
    spdlog::info("{} is stopping the web server...", client_name);
    serverRunning = false;
    spdlog::info("{} web server stopped.", client_name);
}
