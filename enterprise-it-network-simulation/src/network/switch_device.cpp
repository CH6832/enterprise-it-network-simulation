#include "switch_device.hpp"
#include <spdlog/spdlog.h>

SwitchDevice::SwitchDevice(const std::string& deviceName) : name(deviceName) {
    spdlog::info("SwitchDevice '{}' initialized.", name);
}

SwitchDevice::~SwitchDevice() {
    spdlog::info("SwitchDevice '{}' destroyed.", name);
}

void SwitchDevice::handleTraffic(const std::string& source, const std::string& destination) {
    spdlog::info("Switch '{}' handling traffic: {} -> {}", name, source, destination);
}
