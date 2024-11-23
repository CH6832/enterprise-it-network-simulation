#include "ids.hpp"
#include <spdlog/spdlog.h>

IDS::IDS() : intrusionDetected(false) {
    spdlog::info("IDS initialized.");
}

IDS::~IDS() {
    spdlog::info("IDS destroyed.");
}

bool IDS::analyzeTraffic(const std::string& packetData) {
    // Simulated analysis logic
    intrusionDetected = packetData.find("malicious") != std::string::npos;
    if (intrusionDetected) {
        spdlog::warn("Intrusion detected in packet data: {}", packetData);
    }
    else {
        spdlog::info("No intrusion detected in packet data.");
    }
    return intrusionDetected;
}

void IDS::reportIntrusion() const {
    if (intrusionDetected) {
        spdlog::error("Reporting detected intrusion...");
    }
    else {
        spdlog::info("No intrusion to report.");
    }
}
