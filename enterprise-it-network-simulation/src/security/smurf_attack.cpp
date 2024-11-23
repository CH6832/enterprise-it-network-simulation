#include "smurf_attack.hpp"
#include <spdlog/spdlog.h>

SmurfAttack::SmurfAttack() : isUnderAttack(false) {
    spdlog::info("SmurfAttack module initialized.");
}

SmurfAttack::~SmurfAttack() {
    spdlog::info("SmurfAttack module destroyed.");
}

bool SmurfAttack::detectAttack(const std::string& sourceIp) {
    // Simulate attack detection logic
    isUnderAttack = true;
    spdlog::warn("Smurf attack detected from source IP: {}", sourceIp);
    return isUnderAttack;
}

void SmurfAttack::mitigateAttack() {
    if (isUnderAttack) {
        spdlog::info("Mitigating Smurf attack...");
        isUnderAttack = false;
        spdlog::info("Smurf attack successfully mitigated.");
    }
    else {
        spdlog::info("No ongoing Smurf attack to mitigate.");
    }
}
