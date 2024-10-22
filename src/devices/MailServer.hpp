#ifndef MAIL_SERVER_H
#define MAIL_SERVER_H

#include "Device.h" // Include the base Device class header
#include <string>   // Include for string handling
#include <stdexcept> // Include for exception handling

/**
 * @class MailServer
 * @brief Represents a mail server device that can send and receive emails.
 *
 * The MailServer class inherits from the Device class and implements specific
 * functionality for mail operations, such as starting, stopping, sending, 
 * and receiving emails.
 */
class MailServer : public Device {
public:
    /**
     * @brief Constructs a MailServer object with the specified name.
     *
     * Initializes the server's running state to false.
     *
     * @param name The name of the mail server.
     */
    MailServer(const std::string& name);

    /**
     * @brief Starts the mail server.
     *
     * Outputs a message indicating that the mail server is starting.
     * If the server is already running, it does nothing.
     *
     * @throws std::runtime_error If the server cannot be started.
     */
    void start() override;

    /**
     * @brief Stops the mail server.
     *
     * Outputs a message indicating that the mail server is stopping.
     * If the server is not running, it does nothing.
     */
    void stop() override;

    /**
     * @brief Sends an email.
     *
     * Outputs a message indicating that an email is being sent.
     *
     * @param recipient The recipient's email address.
     * @param subject The subject of the email.
     * @param body The body of the email.
     *
     * @throws std::runtime_error If the server is not running.
     */
    void sendEmail(const std::string& recipient, const std::string& subject, const std::string& body);

    /**
     * @brief Receives an email.
     *
     * Outputs a message indicating that an email has been received.
     *
     * @throws std::runtime_error If the server is not running.
     */
    void receiveEmail();

    /**
     * @brief Destructor for the MailServer class.
     *
     * Ensures the mail server is stopped when the object is destroyed.
     */
    ~MailServer();

private:
    bool isRunning; // Indicates if the mail server is currently running

    /**
     * @brief Simulates connecting to the mail service.
     *
     * This function simulates establishing a connection to the mail service.
     *
     * @return True if the connection is successful, otherwise false.
     */
    bool connectToMailService();
};

#endif // MAIL_SERVER_H
