#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include "../src/devices/database_server.hpp"

/**
 * @brief Unit test for the DatabaseServer class.
 */
class DatabaseServerTest : public ::testing::Test {
protected:
    DatabaseServer databaseServer;

    // Setup before each test
    void SetUp() override {
        databaseServer = DatabaseServer("192.168.1.200");
    }

    // Cleanup after each test
    void TearDown() override {
        databaseServer.stopServer();
    }
};

/**
 * @brief Test case for verifying the DatabaseServer initialization.
 */
//TEST_F(DatabaseServerTest, TestInitialization) {
//    ASSERT_EQ(databaseServer.getDeviceName(), "DatabaseServer");
//}

/**
 * @brief Test case to check starting the database server.
 */
TEST_F(DatabaseServerTest, TestStartServer) {
    // Capture stdout
    testing::internal::CaptureStdout();
    databaseServer.startServer();
    std::string output = testing::internal::GetCapturedStdout();

    // Validate the captured logs
    ASSERT_TRUE(output.find("DatabaseServer is starting the database server...") != std::string::npos);
    ASSERT_TRUE(output.find("DatabaseServer database server started.") != std::string::npos);
}

/**
 * @brief Test case to check stopping the database server.
 */
TEST_F(DatabaseServerTest, TestStopServer) {
    databaseServer.startServer();  // Ensure the server is started
    testing::internal::CaptureStdout();
    databaseServer.stopServer();
    std::string output = testing::internal::GetCapturedStdout();

    // Validate the captured logs
    ASSERT_TRUE(output.find("DatabaseServer is stopping the database server...") != std::string::npos);
    ASSERT_TRUE(output.find("DatabaseServer database server stopped.") != std::string::npos);
}

/**
 * @brief Test case to check stopping the database server when it's already stopped.
 */
TEST_F(DatabaseServerTest, TestStopServerAlreadyStopped) {
    // Ensure the server is not started
    testing::internal::CaptureStdout();
    databaseServer.stopServer();
    std::string output = testing::internal::GetCapturedStdout();

    // Validate the captured logs
    ASSERT_TRUE(output.find("DatabaseServer database server is already stopped.") != std::string::npos);
}
