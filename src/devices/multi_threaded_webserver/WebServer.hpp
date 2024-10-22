#ifndef WEBSERVER_HPP
#define WEBSERVER_HPP

#include "Device.hpp"
#include <string>

/**
 * @class WebServer
 * @brief Represents a web server device that can be started and stopped.
 * 
 * The WebServer class inherits from the Device class and provides
 * functionality specific to a web server, such as handling HTTP/HTTPS
 * requests, binding to a network port, and managing client connections.
 */
class WebServer : public Device {
public:
    /**
     * @brief Constructs a WebServer object with a specific name.
     * 
     * @param name The name of the web server.
     */
    WebServer(const std::string& name);

    /**
     * @brief Starts the web server.
     * 
     * This method handles the initialization and startup of the web server,
     * including binding to a network port, setting up HTTP/HTTPS protocols,
     * and configuring request handlers.
     */
    void start() override;

    /**
     * @brief Stops the web server.
     * 
     * This method handles the graceful shutdown of the web server, including
     * terminating active connections and releasing resources.
     */
    void stop() override;

    /**
     * @brief Destructor for the WebServer class.
     * 
     * Ensures that the web server is stopped properly when the object is
     * destroyed.
     */
    ~WebServer();

private:
    bool isRunning;  ///< Tracks whether the web server is currently running.

    /**
     * @brief Simulates binding the web server to a network port.
     * 
     * In a real-world scenario, this would involve actual socket operations.
     * 
     * @return True if the port is successfully bound, false otherwise.
     */
    bool bindToPort();

    /**
     * @brief Initializes the HTTP/HTTPS protocols for the web server.
     * 
     * This sets up the protocols needed for handling client requests.
     */
    void initializeProtocols();

    /**
     * @brief Configures request handling mechanisms for the server.
     * 
     * Sets up the logic for handling different types of HTTP requests.
     */
    void setupRequestHandling();

    /**
     * @brief Simulates closing any active client connections.
     * 
     * This method is called during server shutdown to terminate active connections.
     */
    void closeActiveConnections();

    /**
     * @brief Releases any resources allocated by the web server.
     * 
     * Cleans up memory, file handles, or network sockets that were used during the
     * server's operation.
     */
    void releaseResources();
};

#endif // WEBSERVER_HPP
