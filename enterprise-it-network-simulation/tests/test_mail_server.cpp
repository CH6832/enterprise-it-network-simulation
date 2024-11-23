#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include "../src/devices/mail_server.hpp"

/**
 * @brief Unit test for the MailServer class.
 */
class MailServerTest : public ::testing::Test {
protected:
    MailServer mailServer;

    // Setup before each test
    void SetUp() override {
        mailServer = MailServer("192.168.1.300");
    }

    // Cleanup after each test
    void TearDown() override {
        mailServer.stopServer();
    }
};

/**
 * @brief Test case for verifying the MailServer initialization.
 */
//TEST_F(MailServerTest, TestInitialization) {
//    ASSERT_EQ(mailServer.getClientName(), "MailServer");
//}

/**
 * @brief Test case to check starting the mail server.
 */
TEST_F(MailServerTest, TestStartServer) {
    testing::internal::CaptureStdout();
    mailServer.startServer();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("MailServer is starting the mail server...") != std::string::npos);
    ASSERT_TRUE(output.find("MailServer mail server started.") != std::string::npos);
}

/**
 * @brief Test case to check stopping the mail server.
 */
TEST_F(MailServerTest, TestStopServer) {
    mailServer.startServer();
    testing::internal::CaptureStdout();
    mailServer.stopServer();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("MailServer is stopping the mail server...") != std::string::npos);
    ASSERT_TRUE(output.find("MailServer mail server stopped.") != std::string::npos);
}

/**
 * @brief Test case to check stopping the mail server when it's already stopped.
 */
TEST_F(MailServerTest, TestStopServerAlreadyStopped) {
    testing::internal::CaptureStdout();
    mailServer.stopServer();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("MailServer mail server is already stopped.") != std::string::npos);
}
