#ifndef PROCESS_HPP
#define PROCESS_HPP

/**
 * @class Process
 * @brief Represents a process in the operating system.
 */
class Process {
public:
    int id;          ///< Process ID
    int burstTime;   ///< Burst time for the process
    int waitingTime; ///< Waiting time before the process starts execution
    int priority;    ///< Priority for SJF (lower values indicate higher priority)

    /**
     * @brief Constructor for the Process class.
     * 
     * @param id Process ID.
     * @param burstTime Burst time for the process.
     * @param priority Priority for the process (default is 0).
     */
    Process(int id, int burstTime, int priority = 0);
};

#endif // PROCESS_HPP
