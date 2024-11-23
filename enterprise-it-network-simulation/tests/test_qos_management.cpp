#include <gtest/gtest.h>
#include "qos_management.hpp"

/**
 * @brief Unit tests for the QosManagement class.
 */
class QosManagementTest : public ::testing::Test {
protected:
    QosManagement qosManagement;

    // Setup before each test
    void SetUp() override {
        qosManagement = QosManagement("192.168.1.1");
    }

    // Cleanup after each test
    void TearDown() override {
        qosManagement.removePolicy();
    }
};

/**
 * @brief Test case to verify QoS policy configuration.
 */
TEST_F(QosManagementTest, TestConfigureQoS) {
    EXPECT_NO_THROW(qosManagement.configurePolicy());  // Expect no exception when configuring QoS
}

/**
 * @brief Test case to verify removal of QoS policy.
 */
TEST_F(QosManagementTest, TestRemoveQoS) {
    qosManagement.configurePolicy();
    EXPECT_NO_THROW(qosManagement.removePolicy());  // Expect no exception when removing QoS policy
}
