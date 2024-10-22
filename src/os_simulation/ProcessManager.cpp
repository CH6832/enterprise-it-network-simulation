#include "ProcessManager.hpp"

// Adds a new process to the manager
void ProcessManager::addProcess(const Process& process) {
    processes_.push_back(process);
    std::cout << "Added Process ID: " << process.id << " with Burst Time: " << process.burstTime << " and Priority: " << process.priority << std::endl;
}

// Schedules processes using First-Come, First-Served (FCFS)
void ProcessManager::scheduleFCFS() {
    std::cout << "Scheduling using First-Come, First-Served (FCFS)..." << std::endl;
    int totalWaitingTime = 0;

    for (size_t i = 0; i < processes_.size(); ++i) {
        if (i == 0) {
            processes_[i].waitingTime = 0; // First process
        } else {
            processes_[i].waitingTime = processes_[i - 1].waitingTime + processes_[i - 1].burstTime;
        }
        totalWaitingTime += processes_[i].waitingTime;
    }
    
    displayProcessInfo();
    std::cout << "Average Waiting Time: " << static_cast<double>(totalWaitingTime) / processes_.size() << std::endl;
}

// Schedules processes using Shortest Job First (SJF)
void ProcessManager::scheduleSJF() {
    std::cout << "Scheduling using Shortest Job First (SJF)..." << std::endl;

    // Create a priority queue sorted by burst time
    auto cmp = [](const Process& a, const Process& b) { return a.burstTime > b.burstTime; };
    std::priority_queue<Process, std::vector<Process>, decltype(cmp)> pq(cmp);

    for (const auto& process : processes_) {
        pq.push(process);
    }

    int totalWaitingTime = 0;
    int currentTime = 0;

    while (!pq.empty()) {
        Process current = pq.top();
        pq.pop();
        
        current.waitingTime = currentTime;
        totalWaitingTime += current.waitingTime;
        currentTime += current.burstTime;

        std::cout << "Executed Process ID: " << current.id << " with Waiting Time: " << current.waitingTime << std::endl;
    }
    
    std::cout << "Average Waiting Time: " << static_cast<double>(totalWaitingTime) / processes_.size() << std::endl;
}

// Displays information about the processes
void ProcessManager::displayProcessInfo() {
    std::cout << "Process Information:" << std::endl;
    std::cout << "ID\tBurst Time\tWaiting Time\tPriority" << std::endl;
    for (const auto& process : processes_) {
        std::cout << process.id << "\t" << process.burstTime << "\t\t" << process.waitingTime << "\t\t" << process.priority << std::endl;
    }
}
