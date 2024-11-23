#include "process_management.hpp"
#include <spdlog/spdlog.h>

ProcessManagement::ProcessManagement() : nextProcessId(1) {
    spdlog::info("Process management initialized.");
}

ProcessManagement::~ProcessManagement() {
    spdlog::info("Process management destroyed.");
}

int ProcessManagement::startProcess(const std::string& processName) {
    int pid = nextProcessId++;
    processes[pid] = processName;
    spdlog::info("Started process '{}' with PID {}", processName, pid);
    return pid;
}

void ProcessManagement::stopProcess(int processId) {
    if (processes.erase(processId)) {
        spdlog::info("Stopped process with PID {}", processId);
    }
    else {
        spdlog::warn("Process with PID {} not found.", processId);
    }
}

bool ProcessManagement::isProcessRunning(int processId) const {
    bool running = processes.find(processId) != processes.end();
    spdlog::debug("Process with PID {} is {}.", processId, running ? "running" : "not running");
    return running;
}
