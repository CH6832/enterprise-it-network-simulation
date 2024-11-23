#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include "../src/clients/smartphone_client.hpp"  // Ensure the correct path to header file

/**
 * @brief Unit test for the SmartphoneClient class.
 */
class SmartphoneClientTest : public ::testing::Test {
protected:
    // Create a SmartphoneClient instance for testing
    SmartphoneClient client{ "192.168.1.3" };

    // Setup before each test
    void SetUp() override {
        // This is done already with member initialization, but could be expanded for other setups
    }

    // Cleanup after each test
    void TearDown() override {
        // Perform any necessary cleanup after each test if needed
    }
};

/**
 * @brief Test case for SmartphoneClient constructor initialization.
 */
TEST_F(SmartphoneClientTest, TestSmartphoneInitialization) {
    // Verify that the client name is set correctly (default or provided)
    ASSERT_EQ(client.getClientName(), "SmartphoneClient");
}

/**
 * @brief Test case for testing the connect functionality.
 */
TEST_F(SmartphoneClientTest, TestConnect) {
    // Initially, the client should not be connected
    ASSERT_FALSE(client.isConnected());

    // Capture stdout to check the log output
    testing::internal::CaptureStdout();
    client.connect();  // Call connect method

    // Retrieve the captured output (logs from spdlog)
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the logs contain the expected connection messages
    ASSERT_TRUE(output.find("SmartphoneClient is connecting to VPN...") != std::string::npos);
    ASSERT_TRUE(output.find("SmartphoneClient successfully connected to VPN.") != std::string::npos);

    // After connecting, the client should be marked as connected
    ASSERT_TRUE(client.isConnected());
}

/**
 * @brief Test case for handling connection failure simulation.
 */
TEST_F(SmartphoneClientTest, TestErrorHandlingOnConnectionFailure) {
    // Simulate a connection failure
    client.simulateFailure();  // This should set the client to disconnected

    // Check if the client is disconnected after failure
    ASSERT_FALSE(client.isConnected());

    // Capture stdout to check the log output for failure message
    testing::internal::CaptureStdout();
    client.connect();  // Try connecting again after failure
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the logs contain the expected failure messages
    ASSERT_TRUE(output.find("SmartphoneClient failed to connect due to network issues.") != std::string::npos);
}

/**
 * @brief Test case for checking the disconnection behavior.
 */
TEST_F(SmartphoneClientTest, TestDisconnect) {
    // Initially, the client should not be connected
    ASSERT_FALSE(client.isConnected());

    // Simulate a connection to enable disconnection
    client.connect();
    ASSERT_TRUE(client.isConnected());

    // Capture stdout to check the log output during disconnection
    testing::internal::CaptureStdout();
    client.disconnect();  // Call disconnect method

    // Retrieve the captured output (logs from spdlog)
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the logs contain the expected disconnection messages
    ASSERT_TRUE(output.find("SmartphoneClient is disconnecting from VPN...") != std::string::npos);
    ASSERT_TRUE(output.find("SmartphoneClient successfully disconnected from VPN.") != std::string::npos);

    // After disconnecting, the client should be marked as disconnected
    ASSERT_FALSE(client.isConnected());
}

/**
 * @brief Test case for simulating a random connection failure.
 */
TEST_F(SmartphoneClientTest, TestRandomConnectionFailure) {
    // Capture stdout to check the log output for random failure
    testing::internal::CaptureStdout();
    client.connect();  // Attempt connection

    // Retrieve the captured output (logs from spdlog)
    std::string output = testing::internal::GetCapturedStdout();

    // Check for messages related to connection success or failure
    ASSERT_TRUE(output.find("SmartphoneClient is connecting to VPN...") != std::string::npos);

    // Here we simulate a failure using the random chance (you may need to adjust this based on randomness)
    ASSERT_TRUE(output.find("SmartphoneClient failed to connect due to network issues.") != std::string::npos
        || output.find("SmartphoneClient successfully connected to VPN.") != std::string::npos);
}

/**
 * @brief Test case for simulating network latency.
 */
TEST_F(SmartphoneClientTest, TestNetworkLatency) {
    // Capture stdout to check the log output for network latency simulation
    testing::internal::CaptureStdout();
    // client.simulateNetworkLatency();  // Call simulateNetworkLatency method

    // Retrieve the captured output (logs from spdlog)
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the logs contain the expected latency message
    ASSERT_TRUE(output.find("SmartphoneClient experiencing simulated network latency...") != std::string::npos);
}
