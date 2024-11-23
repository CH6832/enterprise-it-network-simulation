#include "firewall_device.hpp"

FirewallDevice::FirewallDevice(const std::string& ip, const std::string& name)
    : client_name(name), ip_address(ip), enabled(false) {
    spdlog::info("{} created with IP: {}", client_name, ip);
}

void FirewallDevice::enable() {
    if (enabled) {
        spdlog::warn("{} is already enabled.", client_name);
        return;
    }
    spdlog::info("{} is enabling the firewall...", client_name);
    enabled = true;
    spdlog::info("{} firewall enabled.", client_name);
}

void FirewallDevice::disable() {
    if (!enabled) {
        spdlog::warn("{} is already disabled.", client_name);
        return;
    }
    spdlog::info("{} is disabling the firewall...", client_name);
    enabled = false;
    spdlog::info("{} firewall disabled.", client_name);
}
