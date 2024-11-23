#include "packet_handler.hpp"
#include <iostream>
#include <stdexcept>

PacketHandler::PacketHandler() {
    spdlog::info("PacketHandler initialized.");
}

PacketHandler::~PacketHandler() {
    spdlog::info("PacketHandler destroyed.");
}

void PacketHandler::handleTcpPacket(const std::vector<uint8_t>& packet) {
    if (!validatePacket(packet)) {
        spdlog::error("Invalid TCP packet.");
        throw std::invalid_argument("Invalid TCP packet.");
    }

    processPacket(packet, "TCP");
}

void PacketHandler::handleUdpPacket(const std::vector<uint8_t>& packet) {
    if (!validatePacket(packet)) {
        spdlog::error("Invalid UDP packet.");
        throw std::invalid_argument("Invalid UDP packet.");
    }

    processPacket(packet, "UDP");
}

bool PacketHandler::validatePacket(const std::vector<uint8_t>& packet) const {
    if (packet.empty()) {
        spdlog::error("Packet is empty.");
        return false;
    }
    if (!isValidPacketSize(packet)) {
        spdlog::error("Packet size is invalid: {} bytes", packet.size());
        return false;
    }
    spdlog::info("Packet validated successfully.");
    return true;
}

void PacketHandler::processPacket(const std::vector<uint8_t>& packet, const std::string& protocol) {
    spdlog::info("{} packet received. Size: {} bytes.", protocol, packet.size());
    // Simulate processing the packet
    std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simulate delay

    spdlog::info("{} packet processed successfully.", protocol);
}

bool PacketHandler::isValidPacketSize(const std::vector<uint8_t>& packet) const {
    const size_t minSize = 20;  // Minimum valid size for a packet
    const size_t maxSize = 1500;  // Maximum valid size for a packet (similar to MTU)

    if (packet.size() < minSize || packet.size() > maxSize) {
        return false;
    }
    return true;
}
