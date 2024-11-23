#include <gtest/gtest.h>
#include "vpn_tunnel.hpp"

/**
 * @brief Unit tests for the VpnTunnel class.
 */
class VpnTunnelTest : public ::testing::Test {
protected:
    VpnTunnel vpnTunnel;

    // Setup before each test
    void SetUp() override {
        vpnTunnel = VpnTunnel("192.168.1.1");  // Simulate VPN server IP
    }

    // Cleanup after each test
    void TearDown() override {
        vpnTunnel.closeTunnel();
    }
};

/**
 * @brief Test case to verify establishing a VPN tunnel.
 */
TEST_F(VpnTunnelTest, TestEstablishTunnel) {
    EXPECT_NO_THROW(vpnTunnel.establishTunnel());  // Expect no exception when establishing the tunnel
}

/**
 * @brief Test case to verify closing the VPN tunnel.
 */
TEST_F(VpnTunnelTest, TestCloseTunnel) {
    vpnTunnel.establishTunnel();
    EXPECT_NO_THROW(vpnTunnel.closeTunnel());  // Expect no exception when closing the tunnel
}

/**
 * @brief Test case to verify handling failure when trying to close an already closed tunnel.
 */
TEST_F(VpnTunnelTest, TestCloseAlreadyClosedTunnel) {
    EXPECT_NO_THROW(vpnTunnel.closeTunnel());  // Expect no exception for closing an already closed tunnel
}
