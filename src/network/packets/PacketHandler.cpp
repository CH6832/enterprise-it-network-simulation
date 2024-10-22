#include "PacketHandler.hpp"
#include <iostream>
#include <iomanip> // for formatting output

void PacketHandler::handlePacket(const std::vector<uint8_t>& packet) {
    // Validate packet structure and integrity
    if (!validatePacket(packet)) {
        throw std::invalid_argument("Invalid packet received");
    }

    // Extract and display header information
    std::string header = extractHeader(packet);
    std::cout << "Packet Header: " << header << std::endl;

    // Extract payload
    std::vector<uint8_t> payload = extractPayload(packet);
    std::cout << "Packet Payload Size: " << payload.size() << " bytes" << std::endl;

    // Log packet details for further analysis
    logPacketDetails(packet);

    // Process the payload (this can be extended based on use case)
    std::cout << "Packet processed successfully." << std::endl;
}

bool PacketHandler::validatePacket(const std::vector<uint8_t>& packet) {
    if (packet.size() < 20) {  // Assume minimum packet size of 20 bytes
        std::cerr << "Packet too small!" << std::endl;
        return false;
    }

    // Additional validation logic could include checksum, version, etc.
    std::cout << "Packet validation successful." << std::endl;
    return true;
}

std::string PacketHandler::extractHeader(const std::vector<uint8_t>& packet) {
    // Here we simulate extracting some header information
    std::string protocol = (packet[0] == 0x01) ? "TCP" : "UDP";  // Simulate protocol check
    uint16_t length = packet.size();

    return "Protocol: " + protocol + ", Length: " + std::to_string(length);
}

std::vector<uint8_t> PacketHandler::extractPayload(const std::vector<uint8_t>& packet) {
    // Assuming first 20 bytes are the header
    std::vector<uint8_t> payload(packet.begin() + 20, packet.end());
    return payload;
}

void PacketHandler::logPacketDetails(const std::vector<uint8_t>& packet) {
    std::cout << "Logging packet details: " << std::endl;
    std::cout << "Packet Hex Dump:" << std::endl;
    
    for (size_t i = 0; i < packet.size(); ++i) {
        if (i % 16 == 0) {
            std::cout << std::endl << std::setw(4) << std::setfill('0') << i << ": ";
        }
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(packet[i]) << " ";
    }
    std::cout << std::dec << std::endl; // Reset to decimal output
}
