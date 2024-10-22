#include "server.hpp"
#include "thread_pool.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <mutex>
#include <chrono>
#include <thread>
#include <unordered_map>
#include "token_bucket.hpp"
#include <curl/curl.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/opensslv.h>

#ifdef _WIN32
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
#endif

std::mutex log_mutex; // Mutex for thread-safe logging

/**
 * @class Server
 * @brief A simple HTTP server that handles client connections.
 *
 * This class provides functionality for creating a TCP server that can handle
 * incoming HTTP requests, serving static files, and managing concurrent connections.
 */
class Server {
public:
    Server(int port);
    ~Server();
    void start();

private:
    int create_server_socket(int port);
    void cleanup();
    void log_message(const std::string& message);
    std::string handle_request(const std::string& request);
    void handle_client(int client_socket);
    void handle_connections();
    std::string get_mime_type(const std::string& path);

    int port;             ///< The port on which the server will listen for incoming connections.
    int server_fd;        ///< The file descriptor for the server socket.
#ifdef _WIN32
    // Windows-specific members
#else
    int epoll_fd;        ///< The file descriptor for the epoll instance (Linux only).
#endif
};

/**
 * @brief Constructs a Server object.
 * @param port The port number on which the server will listen.
 */
Server::Server(int port) 
    : port(port), server_fd(-1)
#ifdef _WIN32
{}
#else
, epoll_fd(-1)
{}
#endif

/**
 * @brief Destructor that cleans up resources.
 *
 * This destructor ensures that all sockets and associated resources
 * are properly closed and released to prevent memory leaks.
 */
Server::~Server() {
    cleanup();
}

/**
 * @brief Cleans up the server's resources.
 *
 * This method closes the server socket and any other open file descriptors.
 */
void Server::cleanup() {
#ifdef _WIN32
    if (server_fd != INVALID_SOCKET) closesocket(server_fd);
    WSACleanup(); // Cleanup Windows sockets
#else
    if (server_fd >= 0) close(server_fd);
    if (epoll_fd >= 0) close(epoll_fd);
#endif
}

/**
 * @brief Creates a server socket and binds it to the specified port.
 * @param port The port number to bind the server socket to.
 * @return The file descriptor for the server socket, or -1 on failure.
 */
int Server::create_server_socket(int port) {
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        log_message("WSAStartup failed");
        return -1;
    }
#endif

    // Create a TCP socket
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == INVALID_SOCKET) {
        log_message("Socket creation failed");
        cleanup();
        return -1;
    }

    // Set the socket to non-blocking mode
    u_long mode = 1; // 1 to enable non-blocking mode
#ifdef _WIN32
    if (ioctlsocket(fd, FIONBIO, &mode) != NO_ERROR) {
#else
    if (fcntl(fd, F_SETFL, O_NONBLOCK) == -1) {
#endif
        log_message("Failed to set non-blocking mode");
        closesocket(fd);
        cleanup();
        return -1;
    }

    sockaddr_in address = {0}; // Initialize address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    address.sin_port = htons(port); // Convert port to network byte order

    // Bind the socket to the specified port
    if (bind(fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        log_message("Bind failed");
        closesocket(fd);
        cleanup();
        return -1;
    }

    // Listen for incoming connections
    if (listen(fd, SOMAXCONN) == SOCKET_ERROR) {
        log_message("Listen failed");
        closesocket(fd);
        cleanup();
        return -1;
    }

    return fd; // Return the valid server socket
}

/**
 * @brief Logs a message to the console in a thread-safe manner.
 * @param message The message to log.
 */
void Server::log_message(const std::string& message) {
    std::lock_guard<std::mutex> guard(log_mutex); // Lock the mutex for thread safety
    std::cout << message << std::endl; // Print the message to the console
}

/**
 * @brief Handles an incoming HTTP request and returns the response.
 * @param request The HTTP request string received from the client.
 * @return The HTTP response string to be sent back to the client.
 */
std::string Server::handle_request(const std::string& request) {
    std::istringstream request_stream(request); // Stream for parsing the request
    std::string method, path, version;
    request_stream >> method >> path >> version; // Extract the method, path, and version

    // Handle only GET requests for now
    if (method == "GET") {
        if (path == "/") path = "/index.html"; // Default file for root
        path = "." + path; // Prepend the current directory to the path

        // Open the requested file
        std::ifstream file(path, std::ios::binary);
        if (file) {
            std::ostringstream contents;
            contents << file.rdbuf(); // Read the file's content
            std::string body = contents.str(); // Store the content in a string
            // Create a response string with the appropriate headers
            std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: " + std::to_string(body.size()) + "\r\n\r\n" + body;
            return response; // Return the successful response
        } else {
            return "HTTP/1.1 404 Not Found\r\n\r\n"; // File not found response
        }
    } else {
        return "HTTP/1.1 400 Bad Request\r\n\r\n"; // Bad request response for unsupported methods
    }
}

/**
 * @brief Handles client connections, reading requests and sending responses.
 * @param client_socket The socket descriptor for the connected client.
 */
void Server::handle_client(int client_socket) {
    char buffer[1024] = { 0 }; // Buffer for reading data from the client
    ssize_t bytes_read = read(client_socket, buffer, sizeof(buffer) - 1); // Read data

    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        std::string request(buffer); // Create a string from the buffer
        log_message("Received request:\n" + request); // Log the received request

        // Process the request and get the response
        std::string response = handle_request(request);
        send(client_socket, response.c_str(), response.size(), 0); // Send the response
    } else {
        log_message("Failed to read from client socket"); // Log read failure
    }

    closesocket(client_socket); // Close the client socket
}

/**
 * @brief Main loop for accepting and handling incoming connections.
 */
void Server::handle_connections() {
    // Windows-specific handling for IOCP
#ifdef _WIN32
    HANDLE iocp = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    if (iocp == NULL) {
        log_message("Failed to create IOCP");
        return;
    }

    // Associate the server socket with the IOCP
    if (CreateIoCompletionPort((HANDLE)server_fd, iocp, (ULONG_PTR)server_fd, 0) == NULL) {
        log_message("Failed to associate server socket with IOCP");
        return;
    }

    ThreadPool thread_pool(4); // Create a thread pool for handling requests

    while (true) {
        DWORD bytesTransferred;
        ULONG_PTR completionKey;
        OVERLAPPED* overlapped = nullptr;

        // Wait for a completed IO operation
        BOOL result = GetQueuedCompletionStatus(iocp, &bytesTransferred, &completionKey, &overlapped, INFINITE);
        if (!result) {
            log_message("Failed in GetQueuedCompletionStatus");
            continue;
        }

        SOCKET client_socket = (SOCKET)completionKey; // Get the client socket

        if (client_socket == server_fd) {
            // Accept new connections
            while (true) {
                SOCKET client_socket = accept(server_fd, nullptr, nullptr);
                if (client_socket == INVALID_SOCKET) {
                    if (WSAGetLastError() == WSAEWOULDBLOCK) break; // No more connections
                    log_message("Accept failed");
                    continue;
                }

                // Associate the new client socket with the IOCP
                CreateIoCompletionPort((HANDLE)client_socket, iocp, (ULONG_PTR)client_socket, 0);
                thread_pool.enqueue([this, client_socket] { handle_client(client_socket); });
            }
        }
    }
#else
    // Linux-specific handling for epoll
    epoll_fd = epoll_create1(0);
    if (epoll_fd < 0) {
        log_message("Failed to create epoll instance");
        return;
    }

    epoll_event event = {};
    event.events = EPOLLIN; // Listen for incoming connections
    event.data.fd = server_fd; // Associate the server socket with the epoll instance
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &event); // Add server socket to epoll

    ThreadPool thread_pool(4); // Create a thread pool for handling requests

    while (true) {
        epoll_event events[10]; // Buffer for events
        int num_events = epoll_wait(epoll_fd, events, 10, -1); // Wait for events

        for (int i = 0; i < num_events; i++) {
            if (events[i].data.fd == server_fd) {
                // Accept new connections
                while (true) {
                    int client_socket = accept(server_fd, nullptr, nullptr);
                    if (client_socket < 0) {
                        if (errno == EAGAIN || errno == EWOULDBLOCK) break; // No more connections
                        log_message("Accept failed");
                        continue;
                    }

                    // Set the client socket to non-blocking
                    fcntl(client_socket, F_SETFL, O_NONBLOCK);
                    thread_pool.enqueue([this, client_socket] { handle_client(client_socket); });
                }
            }
        }
    }
#endif
}

/**
 * @brief Starts the server and begins listening for incoming connections.
 */
void Server::start() {
    server_fd = create_server_socket(port); // Create and bind the server socket
    if (server_fd < 0) {
        log_message("Failed to create server socket");
        return;
    }
    log_message("Server started on port " + std::to_string(port)); // Log server start message
    handle_connections(); // Start handling connections
}

/**
 * @brief Retrieves the MIME type based on the file extension.
 * @param path The file path for which to determine the MIME type.
 * @return The MIME type as a string.
 */
std::string Server::get_mime_type(const std::string& path) {
    if (path.ends_with(".html") || path.ends_with(".htm")) return "text/html";
    else if (path.ends_with(".css")) return "text/css";
    else if (path.ends_with(".js")) return "application/javascript";
    else if (path.ends_with(".json")) return "application/json";
    else if (path.ends_with(".jpg") || path.ends_with(".jpeg")) return "image/jpeg";
    else if (path.ends_with(".png")) return "image/png";
    else return "application/octet-stream"; // Default MIME type
}
