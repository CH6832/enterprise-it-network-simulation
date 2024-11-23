#include "vpn_server.hpp"

VPNServer::VPNServer(const std::string& ip, const std::string& name)
    : client_name(name), ip_address(ip), serverRunning(false) {
    spdlog::info("{} created with IP: {}", client_name, ip);
}

void VPNServer::startServer() {
    if (serverRunning) {
        spdlog::warn("{} VPN server is already running.", client_name);
        return;
    }
    spdlog::info("{} is starting the VPN server...", client_name);
    serverRunning = true;
    spdlog::info("{} VPN server started.", client_name);
}

void VPNServer::stopServer() {
    if (!serverRunning) {
        spdlog::warn("{} VPN server is already stopped.", client_name);
        return;
    }
    spdlog::info("{} is stopping the VPN server...", client_name);
    serverRunning = false;
    spdlog::info("{} VPN server stopped.", client_name);
}
