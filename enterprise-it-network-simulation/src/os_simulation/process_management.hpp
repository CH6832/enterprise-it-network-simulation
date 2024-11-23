#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include <string>
#include <map>

/**
 * @brief Simulates process management for network devices.
 */
class ProcessManagement {
public:
    ProcessManagement();
    ~ProcessManagement();

    /**
     * @brief Starts a new process.
     * @param processName Name of the process to start.
     * @return Process ID.
     */
    int startProcess(const std::string& processName);

    /**
     * @brief Stops a running process.
     * @param processId ID of the process to stop.
     */
    void stopProcess(int processId);

    /**
     * @brief Checks the status of a process.
     * @param processId ID of the process.
     * @return True if running, false otherwise.
     */
    bool isProcessRunning(int processId) const;

private:
    int nextProcessId; /**< Counter for process IDs */
    std::map<int, std::string> processes; /**< Map of process ID to process names */
};

#endif // PROCESS_MANAGEMENT_HPP
