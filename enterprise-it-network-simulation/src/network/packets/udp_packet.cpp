#include "udp_packet.hpp"
#include <spdlog/spdlog.h>

UdpPacket::UdpPacket(const std::string& srcIp, const std::string& destIp, int dataSize)
    : sourceIP(srcIp), destinationIP(destIp), dataSize(dataSize) {
    spdlog::info("UDP Packet created: {} -> {} ({} bytes)", sourceIP, destinationIP, dataSize);
}

UdpPacket::~UdpPacket() {
    spdlog::info("UDP Packet destroyed: {} -> {}", sourceIP, destinationIP);
}

std::string UdpPacket::getSourceIP() const {
    spdlog::debug("Get source IP: {}", sourceIP);
    return sourceIP;
}

std::string UdpPacket::getDestinationIP() const {
    spdlog::debug("Get destination IP: {}", destinationIP);
    return destinationIP;
}

int UdpPacket::getDataSize() const {
    spdlog::debug("Get data size: {} bytes", dataSize);
    return dataSize;
}
