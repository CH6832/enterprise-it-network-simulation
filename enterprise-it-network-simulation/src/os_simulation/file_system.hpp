#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <string>
#include <fstream>
#include <stdexcept>
#include <spdlog/spdlog.h>
#include <vector>

/**
 * @brief A class that simulates basic file system operations.
 */
class FileSystem {
public:
    /**
     * @brief Constructor for FileSystem.
     */
    FileSystem();

    /**
     * @brief Destructor for FileSystem.
     */
    ~FileSystem();

    /**
     * @brief Reads the contents of a file.
     * @param filePath Path to the file to be read.
     * @return The contents of the file as a string.
     * @throws std::runtime_error if reading the file fails.
     */
    std::string readFile(const std::string& filePath) const;

    /**
     * @brief Writes data to a file.
     * @param filePath Path to the file to be written to.
     * @param data The data to write to the file.
     * @throws std::runtime_error if writing to the file fails.
     */
    void writeFile(const std::string& filePath, const std::string& data) const;

    /**
     * @brief Appends data to a file.
     * @param filePath Path to the file to append to.
     * @param data The data to append to the file.
     * @throws std::runtime_error if appending to the file fails.
     */
    void appendToFile(const std::string& filePath, const std::string& data) const;

private:
    /**
     * @brief Helper function to open a file stream.
     * @param filePath Path to the file.
     * @param mode The mode in which to open the file.
     * @param fileStream The stream to open.
     * @throws std::runtime_error if the file cannot be opened.
     */
    void openFileStream(const std::string& filePath, std::ios_base::openmode mode, std::fstream& fileStream) const;
};

#endif // FILESYSTEM_HPP
