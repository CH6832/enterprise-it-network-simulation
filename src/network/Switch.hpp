#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

/**
 * @class Switch
 * @brief Simulates a network switch that forwards traffic based on MAC addresses.
 */
class Switch {
public:
    /**
     * @brief Constructor for the Switch class.
     * 
     * Initializes a new instance of the Switch.
     */
    Switch();

    /**
     * @brief Forwards traffic based on the destination MAC address.
     * 
     * @param sourceMac The source MAC address of the incoming frame.
     * @param destMac The destination MAC address of the frame.
     * @param port The port number the frame is arriving on.
     */
    void forwardTraffic(const std::string& sourceMac, const std::string& destMac, int port);

    /**
     * @brief Displays the current MAC address table.
     */
    void displayMacAddressTable() const;

private:
    std::unordered_map<std::string, int> macAddressTable_;  ///< Stores MAC addresses and their corresponding port numbers.
    std::unordered_map<int, bool> portStatus_;              ///< Stores the status of each port (enabled/disabled).

    /**
     * @brief Learns the source MAC address and updates the MAC address table.
     * 
     * @param sourceMac The source MAC address of the incoming frame.
     * @param port The port number the frame is arriving on.
     */
    void learnMacAddress(const std::string& sourceMac, int port);

    /**
     * @brief Forwards the frame based on the destination MAC address.
     * 
     * @param destMac The destination MAC address of the frame.
     * @param port The port number the frame is arriving on.
     */
    void forwardToPort(const std::string& destMac, int port);
};

#endif // SWITCH_HPP
