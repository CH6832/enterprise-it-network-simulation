#include "layer2_filter.hpp"
#include <spdlog/spdlog.h>
#include <algorithm>

Layer2Filter::Layer2Filter() {
    spdlog::info("Layer2Filter initialized.");
}

Layer2Filter::~Layer2Filter() {
    spdlog::info("Layer2Filter destroyed.");
}

void Layer2Filter::applyMACFilter(const std::string& mac) {
    if (std::find(macFilters.begin(), macFilters.end(), mac) == macFilters.end()) {
        macFilters.push_back(mac);
        spdlog::info("Applied MAC filter: {}", mac);
    }
    else {
        spdlog::warn("MAC filter for {} already exists.", mac);
    }
}

void Layer2Filter::clearFilters() {
    macFilters.clear();
    spdlog::info("All MAC filters cleared.");
}

bool Layer2Filter::isMACAllowed(const std::string& mac) const {
    bool allowed = std::find(macFilters.begin(), macFilters.end(), mac) != macFilters.end();
    spdlog::debug("MAC address {} is {}.", mac, allowed ? "allowed" : "blocked");
    return allowed;
}
