#include "tcp_udp_limits.hpp"
#include <spdlog/spdlog.h>

TcpUdpLimits::TcpUdpLimits(int maxConnections)
    : maxConnections(maxConnections), currentConnections(0) {
    spdlog::info("TcpUdpLimits initialized with max connections: {}", maxConnections);
}

TcpUdpLimits::~TcpUdpLimits() {
    spdlog::info("TcpUdpLimits destroyed.");
}

bool TcpUdpLimits::registerConnection() {
    if (currentConnections >= maxConnections) {
        spdlog::error("Connection limit reached. Cannot register new connection.");
        return false;
    }
    ++currentConnections;
    spdlog::info("New connection registered. Active connections: {}", currentConnections);
    return true;
}

void TcpUdpLimits::deregisterConnection() {
    if (currentConnections > 0) {
        --currentConnections;
        spdlog::info("Connection deregistered. Active connections: {}", currentConnections);
    }
    else {
        spdlog::warn("No active connections to deregister.");
    }
}

int TcpUdpLimits::getActiveConnections() const {
    spdlog::debug("Query active connections: {}", currentConnections);
    return currentConnections;
}
