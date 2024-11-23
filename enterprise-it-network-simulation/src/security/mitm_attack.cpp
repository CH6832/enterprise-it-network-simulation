#include "mitm_attack.hpp"
#include <spdlog/spdlog.h>

MitmAttack::MitmAttack() : isAttackDetected(false) {
    spdlog::info("MITM attack module initialized.");
}

MitmAttack::~MitmAttack() {
    spdlog::info("MITM attack module destroyed.");
}

bool MitmAttack::detectAttack(const std::string& victimIp) {
    // Simulated logic for detecting MITM attack
    isAttackDetected = true;
    spdlog::warn("MITM attack detected targeting victim IP: {}", victimIp);
    return isAttackDetected;
}

void MitmAttack::preventAttack() {
    if (isAttackDetected) {
        spdlog::info("Preventing MITM attack...");
        isAttackDetected = false;
        spdlog::info("MITM attack successfully prevented.");
    }
    else {
        spdlog::info("No MITM attack detected to prevent.");
    }
}
