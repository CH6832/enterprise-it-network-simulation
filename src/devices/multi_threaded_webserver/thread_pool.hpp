#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <stdexcept>

/**
 * @class ThreadPool
 * @brief A thread pool that manages a set of worker threads to execute tasks concurrently.
 *
 * This class provides a pool of threads to execute functions asynchronously. 
 * It manages a queue of tasks and provides methods to enqueue new tasks for execution.
 */
class ThreadPool {
public:
    /**
     * @brief Construct a ThreadPool with a specified number of threads.
     * 
     * @param threads The number of worker threads to create.
     */
    ThreadPool(size_t threads);

    /**
     * @brief Destructor for the ThreadPool class.
     *
     * This method stops all worker threads and waits for their completion.
     */
    ~ThreadPool();

    /**
     * @brief Enqueue a new task for execution.
     *
     * This method adds a new function to the task queue, which will be executed 
     * by one of the available worker threads.
     *
     * @tparam F The type of the callable function to enqueue.
     * @param f The callable function to be executed.
     * @throws std::runtime_error if attempting to enqueue a task on a stopped ThreadPool.
     */
    template<class F>
    void enqueue(F&& f);

private:
    std::vector<std::thread> workers; ///< The vector of worker threads.
    std::queue<std::function<void()>> tasks; ///< The queue of tasks to be executed.

    std::mutex queue_mutex; ///< Mutex for synchronizing access to the task queue.
    std::condition_variable condition; ///< Condition variable for notifying worker threads.
    bool stop; ///< Flag to indicate whether the ThreadPool is stopping.
};

// Template function definition
/**
 * @brief Template function to enqueue a new task in the ThreadPool.
 *
 * This method allows adding a callable function to the task queue. 
 * The function will be executed by one of the worker threads when it becomes available.
 *
 * @tparam F The type of the callable function to enqueue.
 * @param f The callable function to be executed.
 */
template<class F>
void ThreadPool::enqueue(F&& f) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex); // Lock the mutex to safely access the task queue
        if (stop) throw std::runtime_error("enqueue on stopped ThreadPool"); // Check if ThreadPool is stopped

        tasks.emplace(std::forward<F>(f)); // Add the task to the queue
    }
    condition.notify_one(); // Notify one waiting thread that a new task is available
}

#endif // THREAD_POOL_H
