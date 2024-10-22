#ifndef COMMANDLINEINTERFACE_HPP
#define COMMANDLINEINTERFACE_HPP

#include <iostream>
#include <string>
#include <vector>

/**
 * @class CommandLineInterface
 * @brief Provides a command-line interface for OS interaction.
 */
class CommandLineInterface {
public:
    /**
     * @brief Prompts the user for input and processes commands.
     * 
     * This method continuously prompts the user until the 'exit' command
     * is entered. It supports basic command processing and can be extended
     * for more complex commands.
     */
    void prompt() {
        std::cout << "Type 'exit' to quit." << std::endl;
        std::string input;
        while (true) {
            std::cout << "> "; // Display prompt
            std::getline(std::cin, input); // Get user input
            
            // Check if the user wants to exit
            if (input == "exit") {
                std::cout << "Exiting the command line interface." << std::endl;
                break;
            }

            // Process the input command
            processCommand(input);
        }
    }

private:
    /**
     * @brief Processes the user's input command.
     * 
     * @param command The command entered by the user.
     */
    void processCommand(const std::string& command) {
        // Basic command processing logic
        if (command == "help") {
            displayHelp();
        } else if (command == "clear") {
            clearScreen();
        } else {
            std::cout << "You typed: " << command << std::endl; // Echo the command
        }
    }

    /**
     * @brief Displays help information for available commands.
     */
    void displayHelp() {
        std::cout << "Available commands:" << std::endl;
        std::cout << "  - help: Display this help message." << std::endl;
        std::cout << "  - clear: Clear the command line screen." << std::endl;
        std::cout << "  - exit: Exit the command line interface." << std::endl;
    }

    /**
     * @brief Clears the command line screen.
     * 
     * This method sends a system command to clear the console.
     */
    void clearScreen() {
        // Cross-platform screen clearing (Windows/Linux)
        #ifdef _WIN32
            std::system("cls"); // Clear console for Windows
        #else
            std::system("clear"); // Clear console for Unix/Linux
        #endif
    }
};

#endif // COMMANDLINEINTERFACE_HPP
