#include <chrono>   // For time management
#include <mutex>    // For mutex lock
#include <thread>   // For thread management
#include <unordered_map> // For storing data (if needed in the future)

// TokenBucket class implements a token bucket rate limiting algorithm.
// The algorithm allows for controlled rate limiting with the ability to handle bursts.
class TokenBucket {
public:
    // Constructor to initialize the TokenBucket with rate and burst size.
    // @param rate The rate at which tokens are generated (tokens per second).
    // @param burst_size The maximum number of tokens that can be stored in the bucket.
    TokenBucket(int rate, int burst_size)
        : rate(rate), 
          burst_size(burst_size), 
          tokens(burst_size), // Start with the bucket full
          last_refill_time(std::chrono::steady_clock::now()) {} // Set last refill time to now

    // Method to check if a request can proceed based on token availability.
    // @return true if the request is allowed (tokens available), false if denied (no tokens available).
    bool allow() {
        // Lock the mutex to ensure thread safety when accessing shared data
        std::lock_guard<std::mutex> lock(mtx);

        // Get the current time
        auto now = std::chrono::steady_clock::now();
        // Calculate the duration since the last token refill
        std::chrono::duration<double> time_passed = now - last_refill_time;

        // Calculate the number of new tokens to be added based on elapsed time and rate
        int new_tokens = static_cast<int>(time_passed.count() * rate);
        // Update the current number of tokens without exceeding the burst size
        tokens = std::min(tokens + new_tokens, burst_size);
        // Update the last refill time to the current time
        last_refill_time = now;

        // Check if there are tokens available to allow the request
        if (tokens > 0) {
            tokens--; // Decrease the token count for the current request
            return true; // Allow the request
        }

        // If no tokens are available, deny the request (throttle)
        return false; 
    }

private:
    int rate;  // Token generation rate (tokens per second)
    int burst_size;  // Maximum number of tokens that can be held in the bucket
    int tokens;  // Current number of available tokens
    std::chrono::steady_clock::time_point last_refill_time;  // Last time tokens were refilled
    std::mutex mtx;  // Mutex to protect shared data access
};
