#include "Printer.h"  // Include the header for the base Device class
#include <iostream>   // Include for input-output stream operations

/**
 * @class Printer
 * @brief Represents a printer device that can be started and stopped.
 *
 * The Printer class inherits from the Device class and implements specific
 * functionality for printer operations, such as starting and stopping the printer.
 */

/**
 * @brief Constructs a Printer object with the specified name.
 *
 * Initializes the printer device with the given name.
 *
 * @param name The name of the printer device.
 */
Printer::Printer(const std::string& name) : Device(name) {}

/**
 * @brief Starts the printer device.
 *
 * This method outputs a message indicating that the printer is starting.
 * It overrides the start method from the Device base class.
 */
void Printer::start() {
    std::cout << "Starting printer: " << name_ << std::endl;
    // Additional logic can be added here, e.g., initializing printer drivers.
}

/**
 * @brief Stops the printer device.
 *
 * This method outputs a message indicating that the printer is stopping.
 * It overrides the stop method from the Device base class.
 */
void Printer::stop() {
    std::cout << "Stopping printer: " << name_ << std::endl;
    // Additional logic can be added here, e.g., releasing resources.
}

/**
 * @brief Simulates printing a document.
 *
 * This method outputs a message indicating that a document is being printed.
 * It throws an exception if the printer is not started.
 *
 * @param document The name or identifier of the document to print.
 * @throws std::runtime_error If the printer is not started.
 */
void Printer::printDocument(const std::string& document) {
    if (!isRunning) {
        throw std::runtime_error("Printer is not running. Please start the printer before printing.");
    }
    std::cout << "Printing document: " << document << std::endl;
}
