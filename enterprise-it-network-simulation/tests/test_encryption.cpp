#include <gtest/gtest.h>
#include "encryption.hpp"

/**
 * @brief Unit tests for the Encryption class.
 */
class EncryptionTest : public ::testing::Test {
protected:
    Encryption encryption;

    // Setup before each test
    void SetUp() override {
        encryption = Encryption("AES-256");
    }

    // Cleanup after each test
    void TearDown() override {
        encryption.disableEncryption();
    }
};

/**
 * @brief Test case to verify enabling encryption.
 */
TEST_F(EncryptionTest, TestEnableEncryption) {
    EXPECT_NO_THROW(encryption.enableEncryption());  // Expect no exception when enabling encryption
}

/**
 * @brief Test case to verify disabling encryption.
 */
TEST_F(EncryptionTest, TestDisableEncryption) {
    encryption.enableEncryption();
    EXPECT_NO_THROW(encryption.disableEncryption());  // Expect no exception when disabling encryption
}
