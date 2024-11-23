#include <gtest/gtest.h>
#include "switch_device.hpp"

/**
 * @brief Unit tests for the SwitchDevice class.
 */
class SwitchDeviceTest : public ::testing::Test {
protected:
    SwitchDevice switchDevice;

    // Setup before each test
    void SetUp() override {
        switchDevice = SwitchDevice("Switch001");
    }

    // Cleanup after each test
    void TearDown() override {
        switchDevice.deactivate();
    }
};

/**
 * @brief Test case to verify activation of a switch device.
 */
TEST_F(SwitchDeviceTest, TestActivateDevice) {
    EXPECT_NO_THROW(switchDevice.activate());  // Expect no exception when activating the device
}

/**
 * @brief Test case to verify deactivation of a switch device.
 */
TEST_F(SwitchDeviceTest, TestDeactivateDevice) {
    switchDevice.activate();
    EXPECT_NO_THROW(switchDevice.deactivate());  // Expect no exception when deactivating the device
}

/**
 * @brief Test case to verify behavior when trying to deactivate an already deactivated device.
 */
TEST_F(SwitchDeviceTest, TestDeactivateAlreadyDeactivatedDevice) {
    EXPECT_NO_THROW(switchDevice.deactivate());  // Expect no exception for deactivating an already deactivated device
}
