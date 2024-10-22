#include "thread_pool.hpp"  // Include the thread pool header file

/**
 * @class ThreadPool
 * @brief A thread pool implementation to manage and execute tasks concurrently.
 *
 * This class creates a pool of worker threads that can execute tasks in parallel.
 * It manages a task queue and ensures thread safety when accessing the queue.
 */
ThreadPool::ThreadPool(size_t threads) : stop(false) {
    // Create the specified number of worker threads
    for (size_t i = 0; i < threads; ++i) {
        workers.emplace_back([this] {
            // Infinite loop for each worker thread to process tasks
            for (;;) {
                std::function<void()> task;  // Placeholder for the task

                {
                    // Lock the mutex to safely access the task queue
                    std::unique_lock<std::mutex> lock(this->queue_mutex);
                    
                    // Wait for a task to be available or for stop signal
                    this->condition.wait(lock, [this] {
                        return this->stop || !this->tasks.empty();
                    });

                    // If stop signal is received and no tasks are left, exit the loop
                    if (this->stop && this->tasks.empty()) return;

                    // Move the task from the front of the queue
                    task = std::move(this->tasks.front());
                    this->tasks.pop();  // Remove the task from the queue
                }

                // Execute the task
                task();
            }
        });
    }
}

/**
 * @brief Destructor for the ThreadPool class.
 *
 * This method stops all worker threads and joins them, ensuring that
 * all resources are cleaned up properly.
 */
ThreadPool::~ThreadPool() {
    {
        // Lock the mutex to safely update the stop flag
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;  // Signal the threads to stop
    }
    
    // Notify all threads that they should wake up and check the stop condition
    condition.notify_all();

    // Join each worker thread to ensure they complete execution
    for (std::thread& worker : workers) {
        worker.join();  // Wait for the thread to finish
    }
}
