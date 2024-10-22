// token_bucket.cpp
#include "token_bucket.hpp"
#include <chrono>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <algorithm>

// TokenBucket constructor: Initializes the rate of token generation, burst size, the current number of tokens, and the last refill time.
// @param rate The rate at which tokens are generated (tokens per second).
// @param burst_size The maximum number of tokens that can be stored in the bucket.
TokenBucket::TokenBucket(int rate, int burst_size)
    : rate(rate), burst_size(burst_size), tokens(burst_size), last_refill_time(std::chrono::steady_clock::now()) {}

// Check if a request can proceed based on token availability.
// @return true if the request is allowed (tokens available), false if the request is denied (no tokens available).
bool TokenBucket::allow() {
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex for thread safety to prevent race conditions

    // Get the current time
    auto now = std::chrono::steady_clock::now();
    // Calculate the duration since the last token refill
    std::chrono::duration<double> time_passed = now - last_refill_time;

    // Calculate the number of new tokens to be added based on the elapsed time and the rate
    int new_tokens = static_cast<int>(time_passed.count() * rate);
    // Update the token count without exceeding the burst size
    tokens = std::min(tokens + new_tokens, burst_size);
    // Update the last refill time to the current time
    last_refill_time = now;

    // Check if there are tokens available to allow the request
    if (tokens > 0) {
        tokens--;  // Decrease the token count for the current request
        return true;  // Allow the request
    }

    // If no tokens are available, deny the request (throttle)
    return false;
}
