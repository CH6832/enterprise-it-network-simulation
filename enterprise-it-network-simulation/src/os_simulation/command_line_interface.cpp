#include "command_line_interface.hpp"
#include <iostream>

CommandLineInterface::CommandLineInterface() {
    spdlog::info("CommandLineInterface initialized.");

    // Add default commands
    addCommand("help", [this]() { return "Available commands: help, status, exit"; });
    addCommand("exit", [this]() { return "Exiting..."; });
    addCommand("status", [this]() { return "System is running..."; });
}

CommandLineInterface::~CommandLineInterface() {
    spdlog::info("CommandLineInterface destroyed.");
}

void CommandLineInterface::addCommand(const std::string& command, const std::function<std::string()>& handler) {
    commands[command] = handler;
    spdlog::info("Added command: {}", command);
}

std::string CommandLineInterface::processCommand(const std::string& command) {
    auto it = commands.find(command);
    if (it != commands.end()) {
        // Command found, execute it
        return it->second();
    }
    else {
        // Command not found, throw an error
        spdlog::error("Invalid command: {}", command);
        throw std::runtime_error("Command not recognized.");
    }
}

std::string CommandLineInterface::executeCommand(const std::string& command) {
    try {
        spdlog::info("Executing command: {}", command);
        return processCommand(command);
    }
    catch (const std::exception& e) {
        spdlog::error("Error executing command '{}': {}", command, e.what());
        return "Error: " + std::string(e.what());
    }
}
