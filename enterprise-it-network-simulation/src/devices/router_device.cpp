#include "router_device.hpp"

RouterDevice::RouterDevice(const std::string& ip, const std::string& name)
    : client_name(name), ip_address(ip), routing(false) {
    spdlog::info("{} created with IP: {}", client_name, ip);
}

void RouterDevice::startRouting() {
    if (routing) {
        spdlog::warn("{} is already routing.", client_name);
        return;
    }
    spdlog::info("{} is starting routing...", client_name);
    routing = true;
    spdlog::info("{} has started routing.", client_name);
}

void RouterDevice::stopRouting() {
    if (!routing) {
        spdlog::warn("{} is not routing.", client_name);
        return;
    }
    spdlog::info("{} is stopping routing...", client_name);
    routing = false;
    spdlog::info("{} has stopped routing.", client_name);
}
