#ifndef PRINTER_H
#define PRINTER_H

#include "Device.h" // Include the base Device class header
#include <string>   // Include for string handling
#include <stdexcept> // Include for exception handling

/**
 * @class Printer
 * @brief Represents a printer device that can print documents.
 *
 * The Printer class inherits from the Device class and implements specific
 * functionality for printing operations, such as starting, stopping,
 * and printing documents.
 */
class Printer : public Device {
public:
    /**
     * @brief Constructs a Printer object with the specified name.
     *
     * Initializes the printer device with the given name.
     *
     * @param name The name of the printer device.
     */
    Printer(const std::string& name);

    /**
     * @brief Starts the printer device.
     *
     * Outputs a message indicating that the printer is starting.
     */
    void start() override;

    /**
     * @brief Stops the printer device.
     *
     * Outputs a message indicating that the printer is stopping.
     */
    void stop() override;

    /**
     * @brief Prints a document.
     *
     * Outputs a message indicating that a document is being printed.
     *
     * @param document The name or identifier of the document to print.
     *
     * @throws std::runtime_error If the printer is not started.
     */
    void printDocument(const std::string& document);

    /**
     * @brief Destructor for the Printer class.
     *
     * Ensures that any necessary cleanup is performed when the printer object is destroyed.
     */
    ~Printer() {}

private:
    bool isRunning; // Indicates if the printer is currently running
};

#endif // PRINTER_H
