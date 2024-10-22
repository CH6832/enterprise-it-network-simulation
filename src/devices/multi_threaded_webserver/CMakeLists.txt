# CMake project configuration for the Multithreaded Web Server
cmake_minimum_required(VERSION 3.12)  # Set the minimum CMake version required
project(MultithreadedWebserver VERSION 1.0 LANGUAGES CXX)  # Define project name, version, and language

# Add source files to the executable target
add_executable(MultithreadedWebserver 
    main.cpp              # Main entry point for the application
    server.cpp            # Implementation of the server class
    server.hpp            # Header for the server class
    thread_pool.cpp       # Implementation of the thread pool class
    thread_pool.hpp       # Header for the thread pool class
    token_bucket.cpp      # Implementation of the token bucket for rate limiting
    token_bucket.hpp      # Header for the token bucket class
    # Optional test file for the server
    ../tests/test_server.cpp  # Path to the test server code
)

# Set the include directories for external dependencies (like CURL)
# Adjust the path according to your project structure
include_directories(${CMAKE_SOURCE_DIR}/curl/include)  # Include the CURL headers

# Specify the C++ standard for the project
set(CMAKE_CXX_STANDARD 20)  # Use C++20 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Ensure the specified C++ standard is required
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable compiler-specific extensions

# Find and link the required libraries (like CURL)
find_package(CURL REQUIRED)  # Search for the CURL package
target_link_libraries(MultithreadedWebserver PRIVATE CURL::libcurl)  # Link the CURL library

# Optionally add test configurations using CMake's testing features
enable_testing()  # Enable testing in CMake

# Define a custom command to run tests, if needed
add_test(NAME ServerTest COMMAND MultithreadedWebserver ../tests/test_server.cpp)

# TODO: Add install targets if needed for deployment
