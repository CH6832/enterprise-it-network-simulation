#include "threading.hpp"
#include <spdlog/spdlog.h>

Threading::Threading() {
    spdlog::info("Threading module initialized.");
}

Threading::~Threading() {
    if (!threads.empty()) {
        spdlog::warn("Not all threads were joined before destruction.");
        joinAllThreads();
    }
    spdlog::info("Threading module destroyed.");
}

void Threading::startThread(const std::function<void()>& task) {
    try {
        threads.push_back(std::thread(task)); // Start the task in a new thread
        spdlog::info("Thread started successfully.");
    }
    catch (const std::system_error& e) {
        spdlog::error("Thread creation failed: {}", e.what());
        throw std::runtime_error("Thread creation failed.");
    }
}

void Threading::joinAllThreads() {
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join(); // Join the thread (wait for it to finish)
            spdlog::info("Thread joined successfully.");
        }
    }
    threads.clear(); // Clear the list of threads after they have been joined
}
