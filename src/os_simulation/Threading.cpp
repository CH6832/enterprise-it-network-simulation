#include "Threading.hpp" // Assuming you have a corresponding header file
#include <iostream>
#include <thread>
#include <vector>
#include <stdexcept>

/**
 * @brief Simulates multi-threading for processes.
 */
class Threading {
public:
    /**
     * @brief Runs the specified number of threads.
     * 
     * @param numThreads The number of threads to run.
     * @throws std::invalid_argument If numThreads is less than or equal to 0.
     */
    void run(int numThreads) {
        if (numThreads <= 0) {
            throw std::invalid_argument("Number of threads must be greater than 0.");
        }

        std::vector<std::thread> threads; // Vector to hold threads

        // Create and start the specified number of threads
        for (int i = 0; i < numThreads; ++i) {
            threads.emplace_back(&Threading::threadFunction, this, i); // Pass thread index
        }

        // Join all threads to ensure they complete before exiting
        for (auto& t : threads) {
            if (t.joinable()) {
                t.join(); // Wait for the thread to finish
            }
        }
    }

private:
    /**
     * @brief The function executed by each thread.
     * 
     * @param threadIndex The index of the thread (for demonstration).
     */
    void threadFunction(int threadIndex) {
        std::cout << "Running in a separate thread with index: " << threadIndex << "..." << std::endl;
        // Simulate work
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulating work with sleep
    }
};
