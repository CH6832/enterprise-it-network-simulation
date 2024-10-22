#include "Switch.hpp"

Switch::Switch() {
    // Initialize all ports as enabled
    for (int i = 1; i <= 24; ++i) { // Assuming a switch with 24 ports
        portStatus_[i] = true; // All ports are enabled by default
    }
    std::cout << "Switch initialized with 24 ports." << std::endl;
}

void Switch::forwardTraffic(const std::string& sourceMac, const std::string& destMac, int port) {
    // Check if the port is enabled
    if (portStatus_.find(port) == portStatus_.end() || !portStatus_[port]) {
        std::cout << "Error: Port " << port << " is disabled. Cannot forward traffic." << std::endl;
        return;
    }

    // Learn the source MAC address
    learnMacAddress(sourceMac, port);

    // Forward the traffic to the appropriate port
    forwardToPort(destMac, port);
}

void Switch::learnMacAddress(const std::string& sourceMac, int port) {
    macAddressTable_[sourceMac] = port;
    std::cout << "Learned MAC address " << sourceMac << " on port " << port << "." << std::endl;
}

void Switch::forwardToPort(const std::string& destMac, int port) {
    auto it = macAddressTable_.find(destMac);
    if (it != macAddressTable_.end()) {
        // If the destination MAC is in the table, forward to the corresponding port
        int destPort = it->second;
        if (destPort != port) { // Avoid looping back to the same port
            std::cout << "Forwarding traffic to MAC address " << destMac << " on port " << destPort << "." << std::endl;
        } else {
            std::cout << "Traffic destined for the same port. No forwarding needed." << std::endl;
        }
    } else {
        // If the MAC address is not in the table, flood to all ports except the source port
        std::cout << "MAC address " << destMac << " not found in table. Flooding to all ports." << std::endl;
    }
}

void Switch::displayMacAddressTable() const {
    std::cout << "Current MAC Address Table:" << std::endl;
    for (const auto& entry : macAddressTable_) {
        std::cout << "  MAC Address: " << entry.first << " -> Port: " << entry.second << std::endl;
    }
}
