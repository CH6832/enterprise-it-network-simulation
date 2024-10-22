#include "UdpPacket.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>  // For formatting output
#include <numeric>  // For checksum computation

UdpPacket::UdpPacket(uint16_t srcPort, uint16_t destPort, const std::vector<uint8_t>& payload)
    : srcPort_(srcPort), destPort_(destPort), payload_(payload) {
    // Length is the size of header (8 bytes) plus payload size
    length_ = static_cast<uint16_t>(8 + payload_.size());
    // Compute initial checksum (in reality, this would involve more complex calculations)
    checksum_ = computeChecksum();
}

void UdpPacket::transmit() {
    // Validate the packet before transmission
    if (!validatePacket()) {
        throw std::runtime_error("Invalid UDP packet. Transmission aborted.");
    }

    // Simulate the transmission process
    std::cout << "Transmitting UDP packet from port " << srcPort_ 
              << " to port " << destPort_ << "..." << std::endl;

    // Log packet details
    logPacketDetails();

    // Simulate successful transmission
    std::cout << "Packet transmitted successfully." << std::endl;
}

bool UdpPacket::validatePacket() const {
    if (srcPort_ == 0 || destPort_ == 0) {
        std::cerr << "Error: Invalid source or destination port." << std::endl;
        return false;
    }

    if (payload_.empty()) {
        std::cerr << "Error: UDP packet payload is empty." << std::endl;
        return false;
    }

    if (computeChecksum() != checksum_) {
        std::cerr << "Error: Invalid checksum." << std::endl;
        return false;
    }

    return true;
}

uint16_t UdpPacket::computeChecksum() const {
    // A simple checksum computation (sum of all bytes in the payload and header)
    uint32_t sum = srcPort_ + destPort_ + length_;
    for (const auto& byte : payload_) {
        sum += byte;
    }
    // Return the 1's complement of the sum as checksum
    return static_cast<uint16_t>(~(sum & 0xFFFF));
}

void UdpPacket::logPacketDetails() const {
    std::cout << "UDP Packet Details:" << std::endl;
    std::cout << "  Source Port: " << srcPort_ << std::endl;
    std::cout << "  Destination Port: " << destPort_ << std::endl;
    std::cout << "  Length: " << length_ << " bytes" << std::endl;
    std::cout << "  Checksum: " << std::hex << "0x" << checksum_ << std::dec << std::endl;
    std::cout << "  Payload Size: " << payload_.size() << " bytes" << std::endl;

    std::cout << "  Payload (Hex): ";
    for (const auto& byte : payload_) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
    }
    std::cout << std::dec << std::endl;  // Reset to decimal
}
