#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include "../src/clients/notebook_client.hpp"  // Ensure this path is correct

/**
 * @brief Unit test for the NotebookClient class.
 */
class NotebookClientTest : public ::testing::Test {
protected:
    // Create a NotebookClient instance for testing
    NotebookClient notebookClient{ "192.168.1.2" };

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
 * @brief Test case for NotebookClient constructor initialization.
 */
TEST_F(NotebookClientTest, TestConstructorInitialization) {
    // Verify that the client name is set correctly (default or provided)
    ASSERT_EQ(notebookClient.getClientName(), "NotebookClient");
}

/**
 * @brief Test case for testing the connect functionality.
 */
TEST_F(NotebookClientTest, TestConnect) {
    // Capture stdout to check the log output
    testing::internal::CaptureStdout();
    notebookClient.connect();  // Call connect method

    // Retrieve the captured output (logs from spdlog)
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the logs contain the expected connection messages
    ASSERT_TRUE(output.find("NotebookClient is connecting to VPN...") != std::string::npos);
    ASSERT_TRUE(output.find("NotebookClient successfully connected to VPN.") != std::string::npos);
}

/**
 * @brief Test case for testing the disconnect functionality.
 */
TEST_F(NotebookClientTest, TestDisconnect) {
    // Capture stdout to check the log output
    testing::internal::CaptureStdout();
    notebookClient.disconnect();  // Call disconnect method

    // Retrieve the captured output (logs from spdlog)
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the logs contain the expected disconnection messages
    ASSERT_TRUE(output.find("NotebookClient is disconnecting from VPN...") != std::string::npos);
    ASSERT_TRUE(output.find("NotebookClient successfully disconnected from VPN.") != std::string::npos);
}

/**
 * @brief Test case for network latency simulation.
 */
TEST_F(NotebookClientTest, TestNetworkLatency) {
    // Capture stdout to check the log output
    testing::internal::CaptureStdout();
    // notebookClient.simulateNetworkLatency();  // Call simulateNetworkLatency method

    // Retrieve the captured output (logs from spdlog)
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the logs contain the expected latency message
    ASSERT_TRUE(output.find("NotebookClient experiencing simulated network latency...") != std::string::npos);
}

/**
 * @brief Test case for handling connection failure.
 */
TEST_F(NotebookClientTest, TestErrorHandlingOnConnectionFailure) {
    // Simulate a failure scenario
    notebookClient.simulateFailure();  // Simulate failure
    bool connectionStatus = notebookClient.isConnected();

    // Assert that the client is disconnected after failure
    EXPECT_FALSE(connectionStatus); // Verify that the client is no longer connected
}

/**
 * @brief Test case for connecting and disconnecting multiple times.
 */
TEST_F(NotebookClientTest, TestMultipleConnections) {
    // Test multiple connection/disconnection cycles
    notebookClient.connect();
    notebookClient.disconnect();
    notebookClient.connect();
    notebookClient.disconnect();

    // Capture stdout after reconnecting
    testing::internal::CaptureStdout();
    notebookClient.connect();
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the connection message appears after reconnecting
    ASSERT_TRUE(output.find("NotebookClient successfully connected to VPN.") != std::string::npos);
}

/**
 * @brief Test case for verifying the client connection status.
 */
TEST_F(NotebookClientTest, TestClientConnectionStatus) {
    // Initially the client should not be connected
    ASSERT_FALSE(notebookClient.isConnected());

    // Now, simulate a connection
    notebookClient.connect();
    ASSERT_TRUE(notebookClient.isConnected());

    // Simulate a failure and check the status
    notebookClient.simulateFailure();
    ASSERT_FALSE(notebookClient.isConnected());
}
