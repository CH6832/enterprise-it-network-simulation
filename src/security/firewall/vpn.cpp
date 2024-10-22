#include "Vpn.hpp"

// Constructor initializes the VPN server with a name and sets the running state to false
Vpn::Vpn(const std::string& name) : name_(name), isRunning(false) {}

// Starts the VPN server and establishes a connection
void Vpn::start() {
    if (isRunning) {
        std::cout << "VPN server '" << name_ << "' is already running." << std::endl;
        return;
    }

    std::cout << "Starting VPN server: " << name_ << std::endl;
    establishConnection();
    isRunning = true; // Mark the server as running
}

// Stops the VPN server and disconnects the VPN connection
void Vpn::stop() {
    if (!isRunning) {
        std::cout << "VPN server '" << name_ << "' is not running." << std::endl;
        return;
    }

    std::cout << "Stopping VPN server: " << name_ << std::endl;
    disconnect();
    isRunning = false; // Mark the server as not running
}

// Simulates the process of establishing a VPN connection
void Vpn::establishConnection() {
    std::cout << "Establishing VPN connection..." << std::endl;
    // Simulate some connection logic here
}

// Simulates the process of disconnecting from a VPN
void Vpn::disconnect() {
    std::cout << "Disconnecting VPN connection..." << std::endl;
    // Simulate disconnection logic here
}
