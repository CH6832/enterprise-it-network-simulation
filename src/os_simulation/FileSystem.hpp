#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * @class FileSystem
 * @brief Implements a simple file system for file management operations.
 *
 * This class simulates basic file system operations such as creating, deleting,
 * and listing files. It provides an interface for managing files in a simulated environment.
 */
class FileSystem {
public:
    /**
     * @brief Creates a new file with the specified name.
     * 
     * @param fileName The name of the file to be created.
     */
    void createFile(const std::string& fileName) {
        if (fileExists(fileName)) {
            std::cout << "File '" << fileName << "' already exists." << std::endl;
            return; // Exit if the file already exists
        }

        files.push_back(fileName); // Add the new file to the list
        std::cout << "Creating file: " << fileName << std::endl;
    }

    /**
     * @brief Deletes a file with the specified name.
     * 
     * @param fileName The name of the file to be deleted.
     */
    void deleteFile(const std::string& fileName) {
        auto it = std::find(files.begin(), files.end(), fileName);
        if (it != files.end()) {
            files.erase(it); // Remove the file from the list
            std::cout << "Deleting file: " << fileName << std::endl;
        } else {
            std::cout << "File '" << fileName << "' does not exist." << std::endl;
        }
    }

    /**
     * @brief Lists all files in the file system.
     */
    void listFiles() const {
        if (files.empty()) {
            std::cout << "No files in the system." << std::endl;
            return;
        }

        std::cout << "Files in the system:" << std::endl;
        for (const auto& file : files) {
            std::cout << " - " << file << std::endl; // List each file
        }
    }

private:
    std::vector<std::string> files; ///< Vector to store the names of files in the system.

    /**
     * @brief Checks if a file exists in the file system.
     * 
     * @param fileName The name of the file to check.
     * @return True if the file exists, otherwise false.
     */
    bool fileExists(const std::string& fileName) const {
        return std::find(files.begin(), files.end(), fileName) != files.end();
    }
};

#endif // FILESYSTEM_HPP
