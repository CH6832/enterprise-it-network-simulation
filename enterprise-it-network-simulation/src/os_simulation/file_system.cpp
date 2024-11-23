#include "filesystem.hpp"
#include <iostream>
#include <spdlog/spdlog.h>

FileSystem::FileSystem() {
    spdlog::info("FileSystem initialized.");
}

FileSystem::~FileSystem() {
    spdlog::info("FileSystem destroyed.");
}

void FileSystem::openFileStream(const std::string& filePath, std::ios_base::openmode mode, std::fstream& fileStream) const {
    fileStream.open(filePath, mode);
    if (!fileStream.is_open()) {
        spdlog::error("Failed to open file: {}", filePath);
        throw std::runtime_error("Could not open file.");
    }
}

std::string FileSystem::readFile(const std::string& filePath) const {
    std::fstream fileStream;
    openFileStream(filePath, std::ios::in, fileStream);  // Open file in read mode

    std::string content;
    std::string line;

    while (std::getline(fileStream, line)) {
        content += line + "\n";  // Append line to content
    }

    fileStream.close();
    spdlog::info("Successfully read file: {}", filePath);
    return content;
}

void FileSystem::writeFile(const std::string& filePath, const std::string& data) const {
    std::fstream fileStream;
    openFileStream(filePath, std::ios::out | std::ios::trunc, fileStream);  // Open file in write mode (overwrite)

    fileStream << data;

    if (!fileStream.good()) {
        spdlog::error("Failed to write to file: {}", filePath);
        throw std::runtime_error("Error writing to file.");
    }

    fileStream.close();
    spdlog::info("Successfully wrote to file: {}", filePath);
}

void FileSystem::appendToFile(const std::string& filePath, const std::string& data) const {
    std::fstream fileStream;
    openFileStream(filePath, std::ios::out | std::ios::app, fileStream);  // Open file in append mode

    fileStream << data;

    if (!fileStream.good()) {
        spdlog::error("Failed to append to file: {}", filePath);
        throw std::runtime_error("Error appending to file.");
    }

    fileStream.close();
    spdlog::info("Successfully appended to file: {}", filePath);
}
