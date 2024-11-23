#include "rip_routing.hpp"
#include <spdlog/spdlog.h>

RipRouting::RipRouting() {
    spdlog::info("RIP routing initialized.");
}

RipRouting::~RipRouting() {
    spdlog::info("RIP routing destroyed.");
}

void RipRouting::addRoute(const std::string& destination, const std::string& nextHop) {
    routingTable[destination] = nextHop;
    spdlog::info("Route added: {} -> {}", destination, nextHop);
}

void RipRouting::removeRoute(const std::string& destination) {
    if (routingTable.erase(destination)) {
        spdlog::info("Route removed: {}", destination);
    }
    else {
        spdlog::warn("No route found for destination: {}", destination);
    }
}

std::string RipRouting::getNextHop(const std::string& destination) const {
    auto it = routingTable.find(destination);
    if (it != routingTable.end()) {
        spdlog::debug("Next hop for {} is {}", destination, it->second);
        return it->second;
    }
    else {
        spdlog::warn("No route found for destination: {}", destination);
        return "";
    }
}
