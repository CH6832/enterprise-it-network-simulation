#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <vector>
#include <queue>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "Process.hpp" // Ensure that the Process class is included

/**
 * @class Scheduler
 * @brief Manages and schedules processes using different scheduling algorithms.
 */
class Scheduler {
private:
    std::vector<Process> processes; ///< List of processes to be scheduled
    int quantum;                     ///< Time quantum for Round Robin scheduling

public:
    /**
     * @brief Default constructor for the Scheduler class.
     * Initializes the time quantum for Round Robin scheduling.
     */
    Scheduler() : quantum(2) {} // Default time quantum for Round Robin

    /**
     * @brief Sets the time quantum for Round Robin scheduling.
     * 
     * @param q The time quantum to set.
     * @throws std::invalid_argument If the quantum is less than or equal to zero.
     */
    void setQuantum(int q) {
        if (q <= 0) throw std::invalid_argument("Quantum must be greater than 0.");
        quantum = q;
    }

    /**
     * @brief Adds a new process to the scheduler.
     * 
     * @param burstTime The burst time for the new process.
     * @param priority The priority for the new process (default is 0).
     * @throws std::invalid_argument If the burst time is less than or equal to zero.
     */
    void addProcess(int burstTime, int priority = 0) {
        if (burstTime <= 0) throw std::invalid_argument("Burst time must be greater than 0.");
        int id = processes.size() + 1; // Simple ID assignment based on the current size of the vector
        processes.push_back(Process(id, burstTime, priority));
    }

    /**
     * @brief Schedules processes using First-Come, First-Served (FCFS) algorithm.
     * This function implements the logic for FCFS scheduling.
     */
    void scheduleFCFS() {
        std::cout << "\nScheduling processes using First-Come, First-Served (FCFS):\n";
        int currentTime = 0;

        for (auto &p : processes) {
            p.waitingTime = currentTime; // Set waiting time
            currentTime += p.burstTime;   // Update current time
            std::cout << "Process ID: " << p.id 
                      << ", Waiting Time: " << p.waitingTime << std::endl;
        }
    }

    /**
     * @brief Schedules processes using Shortest Job First (SJF) algorithm.
     * This function sorts the processes by burst time and implements SJF logic.
     */
    void scheduleSJF() {
        std::cout << "\nScheduling processes using Shortest Job First (SJF):\n";
        
        // Sort processes by burst time
        std::sort(processes.begin(), processes.end(), [](const Process &a, const Process &b) {
            return a.burstTime < b.burstTime; // Sort by burst time in ascending order
        });

        int currentTime = 0;

        for (auto &p : processes) {
            p.waitingTime = currentTime; // Set waiting time for each process
            currentTime += p.burstTime;   // Update current time
            std::cout << "Process ID: " << p.id 
                      << ", Waiting Time: " << p.waitingTime << std::endl;
        }
    }

    /**
     * @brief Schedules processes using Round Robin algorithm.
     * This function implements Round Robin scheduling with a given quantum time.
     */
    void scheduleRoundRobin() {
        std::queue<Process> q; // Queue for Round Robin scheduling
        int currentTime = 0;

        std::cout << "\nScheduling processes using Round Robin (Quantum: " << quantum << "):\n";

        // Enqueue all processes
        for (auto &p : processes) {
            q.push(p);
        }

        // Process scheduling using Round Robin
        while (!q.empty()) {
            Process p = q.front(); // Get the front process
            q.pop(); // Remove it from the queue

            // Check if the burst time exceeds the quantum
            if (p.burstTime > quantum) {
                currentTime += quantum; // Update current time
                p.burstTime -= quantum; // Decrease the burst time
                q.push(p); // Re-add process to the queue
            } else {
                // Process completes execution
                currentTime += p.burstTime;
                p.waitingTime = currentTime - p.burstTime; // Calculate waiting time
                p.burstTime = 0; // Set burst time to zero (completed)
                std::cout << "Process ID: " << p.id 
                          << ", Waiting Time: " << p.waitingTime << std::endl;
            }
        }
    }
};

#endif // SCHEDULER_HPP
