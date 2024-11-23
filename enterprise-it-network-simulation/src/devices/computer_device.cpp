#include "computer_device.hpp"

ComputerDevice::ComputerDevice(const std::string& ip, const std::string& name)
    : client_name(name), ip_address(ip), connected(false) {
    spdlog::info("{} created with IP: {}", client_name, ip);
}

void ComputerDevice::connect() {
    if (connected) {
        spdlog::warn("{} is already connected.", client_name);
        return;
    }
    spdlog::info("{} is connecting to the network...", client_name);
    connected = true;
    spdlog::info("{} successfully connected to the network.", client_name);
}

void ComputerDevice::disconnect() {
    if (!connected) {
        spdlog::warn("{} is already disconnected.", client_name);
        return;
    }
    spdlog::info("{} is disconnecting from the network...", client_name);
    connected = false;
    spdlog::info("{} successfully disconnected from the network.", client_name);
}

bool ComputerDevice::isConnected() const {
    return connected;
}
