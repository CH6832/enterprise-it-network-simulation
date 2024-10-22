#include "Firewall.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>

/**
 * @class Firewall
 * @brief Represents a network firewall device.
 *
 * The Firewall class inherits from the Device class and implements functionality
 * for managing network traffic based on defined rules, logging events, and 
 * controlling access.
 */
Firewall::Firewall(const std::string& name) : Device(name), isRunning(false) {}

void Firewall::start() {
    if (isRunning) {
        std::cout << "Firewall: " << name_ << " is already running." << std::endl;
        return;  // Prevent starting the firewall if it's already running
    }

    isRunning = true;  // Set state to running
    std::cout << "Starting firewall: " << name_ << std::endl;
}

void Firewall::stop() {
    if (!isRunning) {
        std::cout << "Firewall: " << name_ << " is not running." << std::endl;
        return;  // Prevent stopping the firewall if it's not running
    }

    isRunning = false;  // Set state to not running
    std::cout << "Stopping firewall: " << name_ << std::endl;
}

/**
 * @brief Adds a new rule to the firewall.
 * 
 * @param rule The rule to be added (e.g., "ALLOW 192.168.1.1").
 */
void Firewall::addRule(const std::string& rule) {
    if (!isRunning) {
        std::cout << "Cannot add rule, firewall is not running." << std::endl;
        return;
    }

    rules.push_back(rule);  // Add the new rule to the rules vector
    std::cout << "Added rule: " << rule << std::endl;
}

/**
 * @brief Processes a packet and checks against the firewall rules.
 * 
 * @param ip The IP address of the packet to check.
 * @return True if the packet is allowed, false otherwise.
 */
bool Firewall::processPacket(const std::string& ip) {
    if (!isRunning) {
        std::cout << "Firewall is not running. Dropping packet from: " << ip << std::endl;
        return false;  // If the firewall is not running, drop the packet
    }

    // Check if the packet matches any rules
    for (const auto& rule : rules) {
        if (rule.substr(0, 5) == "ALLOW" && rule.substr(6) == ip) {
            logTraffic(ip, true);  // Log allowed traffic
            return true;  // Allow the packet
        }
    }

    logTraffic(ip, false);  // Log blocked traffic
    return false;  // Block the packet if no rules match
}

/**
 * @brief Logs the traffic for allowed or blocked packets.
 * 
 * @param ip The IP address of the packet being logged.
 * @param allowed Indicates whether the traffic was allowed or blocked.
 */
void Firewall::logTraffic(const std::string& ip, bool allowed) {
    std::ostringstream logEntry;
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    logEntry << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") << " - ";
    logEntry << (allowed ? "ALLOWED" : "BLOCKED") << " packet from: " << ip;

    // Here you could write the logEntry to a file or output it to console
    std::cout << logEntry.str() << std::endl;  // For demonstration, print to console
}

/**
 * @brief Displays the current firewall rules.
 */
void Firewall::showRules() const {
    if (rules.empty()) {
        std::cout << "No rules defined." << std::endl;
        return;
    }

    std::cout << "Current firewall rules:" << std::endl;
    for (const auto& rule : rules) {
        std::cout << " - " << rule << std::endl;  // Print each rule
    }
}

/**
 * @brief Destructor for Firewall class.
 * 
 * Ensures the firewall is stopped when the object is destroyed.
 */
Firewall::~Firewall() {
    if (isRunning) {
        stop();  // Ensure the firewall is stopped upon destruction
    }
}
