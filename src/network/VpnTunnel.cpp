#include "VpnTunnel.hpp"

// Constructor
VpnTunnel::VpnTunnel(const std::string& name) : name_(name), isConnected_(false) {
    std::cout << "VPN Tunnel '" << name_ << "' created." << std::endl;
}

// Connects the VPN tunnel
void VpnTunnel::connect() {
    if (isConnected_) {
        std::cout << "VPN Tunnel '" << name_ << "' is already connected." << std::endl;
        return;
    }
    
    isConnected_ = true;
    std::cout << "Connecting VPN Tunnel '" << name_ << "'..." << std::endl;
    // Simulate the establishment of a secure connection
    std::cout << "VPN Tunnel '" << name_ << "' connected successfully." << std::endl;
}

// Disconnects the VPN tunnel
void VpnTunnel::disconnect() {
    if (!isConnected_) {
        std::cout << "VPN Tunnel '" << name_ << "' is not connected." << std::endl;
        return;
    }

    isConnected_ = false;
    std::cout << "Disconnecting VPN Tunnel '" << name_ << "'..." << std::endl;
    // Simulate cleanup
    std::cout << "VPN Tunnel '" << name_ << "' disconnected successfully." << std::endl;
}

// Sends data through the VPN tunnel
void VpnTunnel::sendData(const std::string& data) {
    if (!isConnected_) {
        std::cout << "Cannot send data. VPN Tunnel '" << name_ << "' is not connected." << std::endl;
        return;
    }

    std::string encryptedData = encrypt(data);
    std::cout << "Sending data through VPN Tunnel '" << name_ << "': " << encryptedData << std::endl;
    dataQueue_.push_back(encryptedData); // Simulate storing sent data
}

// Receives data from the VPN tunnel
std::string VpnTunnel::receiveData() {
    if (!isConnected_) {
        std::cout << "Cannot receive data. VPN Tunnel '" << name_ << "' is not connected." << std::endl;
        return "";
    }

    if (dataQueue_.empty()) {
        std::cout << "No data to receive on VPN Tunnel '" << name_ << "'." << std::endl;
        return "";
    }

    std::string encryptedData = dataQueue_.front();
    dataQueue_.erase(dataQueue_.begin()); // Remove the data from the queue
    std::string decryptedData = decrypt(encryptedData);
    std::cout << "Received data from VPN Tunnel '" << name_ << "': " << decryptedData << std::endl;
    return decryptedData;
}

// Simulates the encryption of data
std::string VpnTunnel::encrypt(const std::string& data) {
    // Simulate simple encryption (for demonstration)
    return "encrypted(" + data + ")";
}

// Simulates the decryption of data
std::string VpnTunnel::decrypt(const std::string& data) {
    // Simulate simple decryption (for demonstration)
    std::string decrypted = data.substr(10, data.length() - 11); // Remove "encrypted(" and ")"
    return decrypted;
}
