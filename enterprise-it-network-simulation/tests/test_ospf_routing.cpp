#include <gtest/gtest.h>
#include "ospf_routing.hpp"

/**
 * @brief Unit tests for the OspfRouting class.
 */
class OspfRoutingTest : public ::testing::Test {
protected:
    OspfRouting ospfRouting;

    // Setup before each test
    void SetUp() override {
        ospfRouting = OspfRouting("192.168.1.0");
    }

    // Cleanup after each test
    void TearDown() override {
        ospfRouting.removeRouting();
    }
};

/**
 * @brief Test case to verify OSPF routing configuration.
 */
TEST_F(OspfRoutingTest, TestConfigureRouting) {
    EXPECT_NO_THROW(ospfRouting.configureRouting());  // Expect no exception when configuring routing
}

/**
 * @brief Test case to verify removal of OSPF routing.
 */
TEST_F(OspfRoutingTest, TestRemoveRouting) {
    ospfRouting.configureRouting();
    EXPECT_NO_THROW(ospfRouting.removeRouting());  // Expect no exception when removing routing
}
