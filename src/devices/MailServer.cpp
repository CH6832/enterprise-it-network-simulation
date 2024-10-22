#include "MailServer.h"                // Include the header for the MailServer class
#include <iostream>                     // Include for input-output stream operations
#include <stdexcept>                    // Include for standard exception handling

/**
 * @brief Constructs a MailServer object with the specified name.
 *
 * Initializes the server's running state to false.
 *
 * @param name The name of the mail server.
 */
MailServer::MailServer(const std::string& name)
    : Device(name), isRunning(false) {} // Initialize isRunning to false

/**
 * @brief Starts the mail server.
 *
 * Outputs a message indicating that the mail server is starting.
 * If the server is already running, it does nothing.
 *
 * @throws std::runtime_error If the server cannot be started.
 */
void MailServer::start() {
    if (isRunning) {
        std::cout << "Mail server: " << name_ << " is already running." << std::endl;
        return; // Prevent starting the server if it's already running
    }

    try {
        // Simulate connection to the mail service
        if (!connectToMailService()) {
            throw std::runtime_error("Failed to connect to the mail service.");
        }

        isRunning = true; // Set state to running
        std::cout << "Starting mail server: " << name_ << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl; // Log the error
    }
}

/**
 * @brief Stops the mail server.
 *
 * Outputs a message indicating that the mail server is stopping.
 * If the server is not running, it does nothing.
 */
void MailServer::stop() {
    if (!isRunning) {
        std::cout << "Mail server: " << name_ << " is not running." << std::endl;
        return; // Prevent stopping the server if it's not running
    }

    // Here you could add any cleanup logic needed before stopping the server

    std::cout << "Stopping mail server: " << name_ << std::endl;
    isRunning = false; // Set state to not running
}

/**
 * @brief Simulates sending an email.
 *
 * Outputs a message indicating that an email is being sent.
 *
 * @param recipient The recipient's email address.
 * @param subject The subject of the email.
 * @param body The body of the email.
 *
 * @throws std::runtime_error If the server is not running.
 */
void MailServer::sendEmail(const std::string& recipient, const std::string& subject, const std::string& body) {
    if (!isRunning) {
        throw std::runtime_error("Cannot send email: mail server is not running.");
    }

    std::cout << "Sending email to: " << recipient << std::endl;
    std::cout << "Subject: " << subject << std::endl;
    std::cout << "Body: " << body << std::endl;
}

/**
 * @brief Simulates receiving an email.
 *
 * Outputs a message indicating that an email has been received.
 *
 * @throws std::runtime_error If the server is not running.
 */
void MailServer::receiveEmail() {
    if (!isRunning) {
        throw std::runtime_error("Cannot receive email: mail server is not running.");
    }

    std::cout << "Receiving email..." << std::endl;
    // Simulate processing received email here
}

/**
 * @brief Simulates connecting to the mail service.
 *
 * This function simulates establishing a connection to the mail service.
 *
 * @return True if the connection is successful, otherwise false.
 */
bool MailServer::connectToMailService() {
    // Simulate a successful connection to the mail service
    return true; // For now, assume the connection is always successful
}

/**
 * @brief Destructor for the MailServer class.
 *
 * Ensures the mail server is stopped when the object is destroyed.
 */
MailServer::~MailServer() {
    if (isRunning) {
        stop(); // Ensure the server is stopped upon destruction
    }
}
