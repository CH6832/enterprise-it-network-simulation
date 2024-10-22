#ifndef SERVER_H
#define SERVER_H

#include <iostream> // For standard input/output stream
#include <string>  // For std::string type

// Include platform-specific headers
#ifdef _WIN32
#include <winsock2.h>      // Windows Sockets API for networking
#include <ws2tcpip.h>     // Additional TCP/IP functions for Windows
#include <Windows.h>       // Windows API
#pragma comment(lib, "ws2_32.lib") // Link against the Winsock library
#else
#include <sys/select.h>    // For the select() function to monitor multiple file descriptors
#include <sys/epoll.h>     // For epoll interface to handle large numbers of file descriptors
#include <unistd.h>        // For Unix standard functions
#endif

/**
 * @class Server
 * @brief A simple HTTP server implementation.
 *
 * This class encapsulates the logic to create and manage an HTTP server
 * that can handle incoming client requests. The implementation is 
 * platform-independent, providing different mechanisms for 
 * Windows and Unix/Linux systems.
 */
class Server {
public:
    /**
     * @brief Constructs a Server object and initializes it with the specified port.
     * 
     * @param port The port number on which the server will listen for incoming connections.
     */
    Server(int port);

    /**
     * @brief Destroys the Server object and cleans up resources.
     */
    ~Server();

    /**
     * @brief Starts the server and begins accepting client connections.
     *
     * This method initializes the server socket, logs the server status,
     * and enters the main event loop to handle incoming client requests.
     */
    void start();

private:
    /**
     * @brief Creates a server socket and binds it to the specified port.
     *
     * @param port The port number to bind the server socket.
     * @return The file descriptor of the created server socket, or -1 on failure.
     */
    int create_server_socket(int port);

    /**
     * @brief Handles communication with a connected client.
     *
     * This method processes requests from the client and sends appropriate
     * responses based on the request type (e.g., GET, POST).
     *
     * @param client_socket The socket descriptor for the connected client.
     */
    void handle_client(int client_socket);

    /**
     * @brief Processes an incoming request and generates a response.
     *
     * @param request The HTTP request string received from the client.
     * @return The HTTP response string to be sent back to the client.
     */
    std::string handle_request(const std::string& request);

    /**
     * @brief Logs messages to the console.
     *
     * This method is thread-safe and uses a mutex to prevent concurrent access
     * to the logging mechanism.
     *
     * @param message The message to log.
     */
    void log_message(const std::string& message);

    /**
     * @brief Manages client connections and dispatches them for handling.
     *
     * This method is responsible for accepting new client connections
     * and delegating them to the appropriate handler for processing.
     */
    void handle_connections();

    /**
     * @brief Handles static files requested by clients.
     *
     * This method reads the contents of static files (e.g., HTML, CSS)
     * and constructs the appropriate HTTP response.
     *
     * @param path The file path of the requested static file.
     * @return The HTTP response containing the file contents or an error message.
     */
    std::string handle_static_file(const std::string& path);

    int server_fd; // File descriptor for the server socket

#ifdef _WIN32
    HANDLE iocp_handle; // IOCP handle for Windows
#else
    int epoll_fd; // epoll file descriptor for Linux
#endif

    const int port; // The port number on which the server listens
};

#endif // SERVER_H
