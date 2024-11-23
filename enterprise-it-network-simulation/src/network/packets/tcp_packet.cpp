#include "tcp_packet.hpp"
#include <spdlog/spdlog.h>

TcpPacket::TcpPacket(const std::string& srcIp, const std::string& destIp, int dataSize)
    : sourceIP(srcIp), destinationIP(destIp), dataSize(dataSize) {
    spdlog::info("TCP Packet created: {} -> {} ({} bytes)", sourceIP, destinationIP, dataSize);
}

TcpPacket::~TcpPacket() {
    spdlog::info("TCP Packet destroyed: {} -> {}", sourceIP, destinationIP);
}

std::string TcpPacket::getSourceIP() const {
    spdlog::debug("Get source IP: {}", sourceIP);
    return sourceIP;
}

std::string TcpPacket::getDestinationIP() const {
    spdlog::debug("Get destination IP: {}", destinationIP);
    return destinationIP;
}

int TcpPacket::getDataSize() const {
    spdlog::debug("Get data size: {} bytes", dataSize);
    return dataSize;
}
