#include "threat_detection.hpp"
#include <spdlog/spdlog.h>

ThreatDetection::ThreatDetection() {
    spdlog::info("ThreatDetection initialized.");
}

ThreatDetection::~ThreatDetection() {
    spdlog::info("ThreatDetection destroyed.");
}

std::vector<std::string> ThreatDetection::scanForThreats() const {
    spdlog::info("Scanning for threats...");
    for (const auto& threat : threats) {
        spdlog::debug("Detected threat: {}", threat);
    }
    return threats;
}

void ThreatDetection::addThreat(const std::string& threatName) {
    threats.push_back(threatName);
    spdlog::info("Added threat: {}", threatName);
}
