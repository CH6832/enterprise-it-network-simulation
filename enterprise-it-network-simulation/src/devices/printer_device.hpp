#ifndef PRINTER_DEVICE_HPP
#define PRINTER_DEVICE_HPP

#include <string>
#include <spdlog/spdlog.h>

/**
 * @brief Simulated network printer device.
 */
class PrinterDevice {
public:
    /**
     * @brief Constructor for PrinterDevice.
     * @param name Name of the printer (default: "Printer").
     * @param ip IP address of the device.
     */
    PrinterDevice(const std::string& ip, const std::string& name = "Printer");

    /**
     * @brief Print a document.
     */
    void printDocument(const std::string& document);

    /**
     * @brief Check if the printer is connected to the network.
     * @return True if connected, false otherwise.
     */
    bool isConnected() const;

private:
    std::string client_name;
    std::string ip_address;
    bool connected;
};

#endif // PRINTER_DEVICE_HPP
