#include "encryption.hpp"
#include <spdlog/spdlog.h>
#include <algorithm>
#include <cctype>

Encryption::Encryption() {
    spdlog::info("Encryption module initialized.");
    generateKey();
}

Encryption::~Encryption() {
    spdlog::info("Encryption module destroyed.");
}

void Encryption::generateKey() {
    // Mock key generation
    key = "mock_secure_key";
    spdlog::info("Encryption key generated: {}", key);
}

std::string Encryption::encrypt(const std::string& plaintext) {
    if (plaintext.empty()) {
        spdlog::error("Encryption failed: plaintext is empty.");
        throw std::invalid_argument("Plaintext cannot be empty.");
    }

    spdlog::info("Encrypting plaintext: {}", plaintext);

    // Mock encryption: reverse the string and append the key
    std::string encrypted = plaintext;
    std::reverse(encrypted.begin(), encrypted.end());
    encrypted += key;

    spdlog::info("Encryption successful: {}", encrypted);
    return encrypted;
}

std::string Encryption::decrypt(const std::string& ciphertext) {
    if (ciphertext.empty()) {
        spdlog::error("Decryption failed: ciphertext is empty.");
        throw std::invalid_argument("Ciphertext cannot be empty.");
    }

    spdlog::info("Decrypting ciphertext: {}", ciphertext);

    // Mock decryption: remove the key and reverse the string
    if (ciphertext.size() <= key.size() || ciphertext.substr(ciphertext.size() - key.size()) != key) {
        spdlog::error("Decryption failed: invalid ciphertext format.");
        throw std::invalid_argument("Invalid ciphertext format.");
    }

    std::string decrypted = ciphertext.substr(0, ciphertext.size() - key.size());
    std::reverse(decrypted.begin(), decrypted.end());

    spdlog::info("Decryption successful: {}", decrypted);
    return decrypted;
}
