#include "printer_device.hpp"

PrinterDevice::PrinterDevice(const std::string& ip, const std::string& name)
    : client_name(name), ip_address(ip), connected(false) {
    spdlog::info("{} created with IP: {}", client_name, ip);
}

void PrinterDevice::printDocument(const std::string& document) {
    if (!connected) {
        spdlog::error("{} cannot print because it is not connected to the network.", client_name);
        return;
    }
    spdlog::info("{} is printing the document: {}", client_name, document);
}

bool PrinterDevice::isConnected() const {
    return connected;
}
