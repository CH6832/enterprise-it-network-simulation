#include <gtest/gtest.h>
#include "packet_handler.hpp"
#include <vector>
#include <stdexcept>

/**
 * @brief Unit tests for PacketHandler class.
 */
class PacketHandlerTest : public ::testing::Test {
protected:
    PacketHandler packetHandler;

    // Setup before each test
    void SetUp() override {
        // No special setup needed for this class.
    }

    // Cleanup after each test
    void TearDown() override {
        // No special cleanup needed.
    }
};

/**
 * @brief Test case to verify handling a valid TCP packet.
 */
TEST_F(PacketHandlerTest, TestHandleTcpPacket) {
    std::vector<uint8_t> tcpPacket = { 0x00, 0x01, 0x02, 0x03, 0x04 };

    EXPECT_NO_THROW(packetHandler.handleTcpPacket(tcpPacket));  // Expect no exception for valid packet
}

/**
 * @brief Test case to verify handling a valid UDP packet.
 */
TEST_F(PacketHandlerTest, TestHandleUdpPacket) {
    std::vector<uint8_t> udpPacket = { 0x05, 0x06, 0x07, 0x08, 0x09 };

    EXPECT_NO_THROW(packetHandler.handleUdpPacket(udpPacket));  // Expect no exception for valid packet
}

/**
 * @brief Test case to verify invalid packet handling.
 */
TEST_F(PacketHandlerTest, TestHandleInvalidPacket) {
    std::vector<uint8_t> invalidPacket;

    EXPECT_THROW(packetHandler.handleUdpPacket(invalidPacket), std::invalid_argument);  // Should throw exception for invalid packet
}

/**
 * @brief Test case to check packet size validation.
 */
TEST_F(PacketHandlerTest, TestInvalidPacketSize) {
    std::vector<uint8_t> largePacket(2000, 0x00);  // Create a packet larger than valid size

    EXPECT_THROW(packetHandler.handleTcpPacket(largePacket), std::invalid_argument);  // Should throw exception for large packet
}
