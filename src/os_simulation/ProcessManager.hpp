#ifndef PROCESS_MANAGER_HPP
#define PROCESS_MANAGER_HPP

#include "Process.hpp"
#include <vector>
#include <queue>
#include <iostream>

/**
 * @class ProcessManager
 * @brief Manages the scheduling and execution of processes.
 */
class ProcessManager {
public:
    /**
     * @brief Adds a new process to the manager.
     * 
     * @param process The process to be added.
     */
    void addProcess(const Process& process);

    /**
     * @brief Executes processes using First-Come, First-Served (FCFS) scheduling.
     */
    void scheduleFCFS();

    /**
     * @brief Executes processes using Shortest Job First (SJF) scheduling.
     */
    void scheduleSJF();

    /**
     * @brief Executes processes using Priority Scheduling.
     */
    void schedulePriority();

private:
    std::vector<Process> processes_; ///< Vector to store all processes.
    void calculateWaitingTimes();     ///< Calculates waiting times for all processes.
    void displayProcessInfo();         ///< Displays information about the processes.
};

#endif // PROCESS_MANAGER_HPP
