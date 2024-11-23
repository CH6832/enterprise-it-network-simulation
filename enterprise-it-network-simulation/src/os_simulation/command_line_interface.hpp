#ifndef COMMAND_LINE_INTERFACE_HPP
#define COMMAND_LINE_INTERFACE_HPP

#include <string>
#include <sstream>
#include <stdexcept>
#include <spdlog/spdlog.h>
#include <vector>
#include <map>

/**
 * @brief A class to simulate a command-line interface (CLI) for interacting with the system.
 */
class CommandLineInterface {
public:
    /**
     * @brief Constructor for CommandLineInterface.
     */
    CommandLineInterface();

    /**
     * @brief Destructor for CommandLineInterface.
     */
    ~CommandLineInterface();

    /**
     * @brief Executes a command given by the user.
     * @param command The command string to execute.
     * @return The output of the command as a string.
     * @throws std::runtime_error if the command is invalid or fails.
     */
    std::string executeCommand(const std::string& command);

    /**
     * @brief Adds a new command to the command handler.
     * @param command The name of the command.
     * @param handler The handler function for the command.
     */
    void addCommand(const std::string& command, const std::function<std::string()>& handler);

private:
    // A map of commands and their corresponding handler functions
    std::map<std::string, std::function<std::string()>> commands;

    /**
     * @brief Parses and processes the command.
     * @param command The command string to process.
     * @return The result of the command execution.
     * @throws std::runtime_error if the command is invalid.
     */
    std::string processCommand(const std::string& command);
};

#endif // COMMAND_LINE_INTERFACE_HPP
