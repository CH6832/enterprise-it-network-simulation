#ifndef FIREWALL_H
#define FIREWALL_H

#include "Device.h"  // Include the base Device class
#include <string>
#include <vector>
#include <mutex>

/**
 * @class Firewall
 * @brief A class representing a network firewall device.
 *
 * The Firewall class inherits from the Device class and manages network traffic 
 * based on defined rules, logs events, and controls access to enhance security.
 */
class Firewall : public Device {
public:
    Firewall(const std::string& name);  // Constructor to initialize the firewall
    ~Firewall();  // Destructor to clean up resources

    void start() override;  // Start the firewall
    void stop() override;   // Stop the firewall

    void addRule(const std::string& rule);  // Add a rule to the firewall
    bool processPacket(const std::string& ip);  // Process a packet and check against rules
    void showRules() const;  // Display the current firewall rules

private:
    void logTraffic(const std::string& ip, bool allowed);  // Log traffic for allowed or blocked packets

    std::vector<std::string> rules;  // Vector to store firewall rules
    bool isRunning;  // State of the firewall (running or not)
    std::mutex mtx;  // Mutex for thread safety
};

#endif // FIREWALL_H
