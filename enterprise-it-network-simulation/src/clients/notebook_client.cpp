#include "notebook_client.hpp"
#include <spdlog/spdlog.h>
#include <chrono>
#include <thread>
#include <random>

/**
 * @brief Simulated notebook VPN client.
 */
NotebookClient::NotebookClient(const std::string& ip, const std::string& name)
    : client_name(name), ip_address(ip), connected(false) {
    spdlog::info("{} created with IP: {}", client_name, ip);
}

void NotebookClient::connect() {
    spdlog::info("{} is connecting to VPN...", client_name);
    simulateNetworkLatency();
    if (simulateRandomFailure()) {
        spdlog::error("{} failed to connect due to network issues.", client_name);
    }
    else {
        connected = true; // Set the client as connected
        spdlog::info("{} successfully connected to VPN.", client_name);
    }
}

void NotebookClient::disconnect() {
    spdlog::info("{} is disconnecting from VPN...", client_name);
    connected = false; // Set the client as disconnected
    simulateNetworkLatency();
    spdlog::info("{} successfully disconnected from VPN.", client_name);
}

std::string NotebookClient::getClientName() const {
    return client_name;
}

bool NotebookClient::isConnected() const {
    spdlog::debug("{} connection status: {}", client_name, connected ? "Connected" : "Disconnected");
    return connected;
}

void NotebookClient::simulateFailure() {
    if (connected) {
        spdlog::error("{} has encountered a connection failure!", client_name);
        connected = false;
    }
    else {
        spdlog::warn("{} cannot simulate failure because it is already disconnected.", client_name);
    }
}

void NotebookClient::simulateNetworkLatency() const {
    spdlog::debug("{} experiencing simulated network latency...", client_name);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

bool NotebookClient::simulateRandomFailure() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int chance = dis(gen);
    spdlog::debug("{} connection failure simulation chance: {}%", client_name, chance);
    return chance <= 10; // 10% chance of failure
}
