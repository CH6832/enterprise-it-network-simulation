#include "vpn_tunnel.hpp"
#include <iostream>
#include <stdexcept>

VpnTunnel::VpnTunnel(const std::string& tunnelAddress)
    : tunnelAddress(tunnelAddress), tunnelActive(false) {
    spdlog::info("VpnTunnel created with address: {}", tunnelAddress);
}

VpnTunnel::~VpnTunnel() {
    if (tunnelActive) {
        stopTunnel();
    }
    spdlog::info("VpnTunnel destroyed.");
}

void VpnTunnel::startTunnel() {
    if (tunnelActive) {
        spdlog::warn("VPN Tunnel is already active.");
        return;  // Tunnel is already active
    }

    spdlog::info("VPN Tunnel is attempting to connect to: {}", tunnelAddress);

    // Simulate the connection process with some delay
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Simulate a successful tunnel connection
    tunnelActive = true;
    spdlog::info("VPN Tunnel connected to {}", tunnelAddress);
}

void VpnTunnel::stopTunnel() {
    if (!tunnelActive) {
        spdlog::warn("VPN Tunnel is not active, no need to stop.");
        return;  // Tunnel is not active
    }

    spdlog::info("VPN Tunnel is disconnecting from: {}", tunnelAddress);

    // Simulate the disconnection process with some delay
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Simulate a successful tunnel disconnection
    tunnelActive = false;
    spdlog::info("VPN Tunnel disconnected from {}", tunnelAddress);
}

bool VpnTunnel::isTunnelActive() const {
    return tunnelActive;
}
