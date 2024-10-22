#include "server.hpp"

/**
 * @brief The entry point of the HTTP server application.
 *
 * This function initializes the Server object, specifying the port
 * number on which the server will listen for incoming connections.
 * It then starts the server and enters the main event loop to handle
 * incoming requests.
 *
 * @return Returns 0 upon successful execution.
 */
int main() {
    const int PORT = 8088; // Define the port number for the server

    // Create a Server object with the specified port
    Server server(PORT);

    // Start the server, which will listen for incoming connections
    server.start();

    return 0; // Indicate successful completion of the program
}
