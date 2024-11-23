#include "threading.hpp"
#include <iostream>

void sampleTask() {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    std::cout << "Task completed in thread: " << std::this_thread::get_id() << std::endl;
}

int main() {
    try {
        Threading threading;

        // Start a few threads to run the sample task
        threading.startThread(sampleTask);
        threading.startThread(sampleTask);
        threading.startThread(sampleTask);

        // Join all threads (wait for them to finish)
        threading.joinAllThreads();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
