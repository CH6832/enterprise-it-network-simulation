#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include "../src/devices/web_server.hpp"

/**
 * @brief Unit test for the WebServer class.
 */
class WebServerTest : public ::testing::Test {
protected:
    WebServer webServer;

    // Setup before each test
    void SetUp() override {
        webServer = WebServer("192.168.1.100");
    }

    // Cleanup after each test
    void TearDown() override {
        webServer.stopServer();
    }
};

/**
 * @brief Test case for verifying the WebServer initialization.
 */
//TEST_F(WebServerTest, TestInitialization) {
//    ASSERT_EQ(webServer.getClientName(), "WebServer");
//}

/**
 * @brief Test case to check starting the web server.
 */
TEST_F(WebServerTest, TestStartServer) {
    testing::internal::CaptureStdout();
    webServer.startServer();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("WebServer is starting the web server...") != std::string::npos);
    ASSERT_TRUE(output.find("WebServer web server started.") != std::string::npos);
}

/**
 * @brief Test case to check stopping the web server.
 */
TEST_F(WebServerTest, TestStopServer) {
    webServer.startServer();
    testing::internal::CaptureStdout();
    webServer.stopServer();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("WebServer is stopping the web server...") != std::string::npos);
    ASSERT_TRUE(output.find("WebServer web server stopped.") != std::string::npos);
}

/**
 * @brief Test case to check stopping the web server when it's already stopped.
 */
TEST_F(WebServerTest, TestStopServerAlreadyStopped) {
    testing::internal::CaptureStdout();
    webServer.stopServer();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("WebServer web server is already stopped.") != std::string::npos);
}
