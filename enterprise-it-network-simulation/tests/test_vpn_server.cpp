#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include "../src/devices/vpn_server.hpp"

/**
 * @brief Unit test for the VPNServer class.
 */
class VPNServerTest : public ::testing::Test {
protected:
    VPNServer vpnServer;

    // Setup before each test
    void SetUp() override {
        vpnServer = VPNServer("192.168.1.400");
    }

    // Cleanup after each test
    void TearDown() override {
        vpnServer.stopServer();
    }
};

/**
 * @brief Test case for verifying the VPNServer initialization.
 */
//TEST_F(VPNServerTest, TestInitialization) {
//    ASSERT_EQ(vpnServer.getClientName(), "VPNServer");
//}

/**
 * @brief Test case to check starting the VPN server.
 */
TEST_F(VPNServerTest, TestStartServer) {
    testing::internal::CaptureStdout();
    vpnServer.startServer();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("VPNServer is starting the VPN server...") != std::string::npos);
    ASSERT_TRUE(output.find("VPNServer VPN server started.") != std::string::npos);
}

/**
 * @brief Test case to check stopping the VPN server.
 */
TEST_F(VPNServerTest, TestStopServer) {
    vpnServer.startServer();
    testing::internal::CaptureStdout();
    vpnServer.stopServer();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("VPNServer is stopping the VPN server...") != std::string::npos);
    ASSERT_TRUE(output.find("VPNServer VPN server stopped.") != std::string::npos);
}

/**
 * @brief Test case to check stopping the VPN server when it's already stopped.
 */
TEST_F(VPNServerTest, TestStopServerAlreadyStopped) {
    testing::internal::CaptureStdout();
    vpnServer.stopServer();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output.find("VPNServer VPN server is already stopped.") != std::string::npos);
}
