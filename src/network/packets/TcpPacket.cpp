#include "TcpPacket.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>  // for formatting output

TcpPacket::TcpPacket(uint16_t srcPort, uint16_t destPort, const std::vector<uint8_t>& payload)
    : srcPort_(srcPort), destPort_(destPort), sequenceNumber_(0), ackNumber_(0), flags_(0), payload_(payload) {
}

void TcpPacket::transmit() {
    // Validate the packet before transmission
    if (!validatePacket()) {
        throw std::runtime_error("Invalid TCP packet. Transmission aborted.");
    }

    // Simulate the transmission process
    std::cout << "Transmitting TCP packet from port " << srcPort_ 
              << " to port " << destPort_ << "..." << std::endl;

    // Log packet details
    logPacketDetails();

    // Simulate successful transmission
    std::cout << "Packet transmitted successfully." << std::endl;
}

bool TcpPacket::validatePacket() const {
    if (srcPort_ == 0 || destPort_ == 0) {
        std::cerr << "Error: Invalid source or destination port." << std::endl;
        return false;
    }

    if (payload_.empty()) {
        std::cerr << "Error: TCP packet payload is empty." << std::endl;
        return false;
    }

    // Additional validation (e.g., sequence numbers, flags) can be added here

    return true;
}

void TcpPacket::logPacketDetails() const {
    std::cout << "TCP Packet Details:" << std::endl;
    std::cout << "  Source Port: " << srcPort_ << std::endl;
    std::cout << "  Destination Port: " << destPort_ << std::endl;
    std::cout << "  Sequence Number: " << sequenceNumber_ << std::endl;
    std::cout << "  Acknowledgment Number: " << ackNumber_ << std::endl;
    std::cout << "  Flags: " << std::bitset<8>(flags_) << std::endl;
    std::cout << "  Payload Size: " << payload_.size() << " bytes" << std::endl;

    std::cout << "  Payload (Hex): ";
    for (const auto& byte : payload_) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
    }
    std::cout << std::dec << std::endl;  // Reset to decimal
}
