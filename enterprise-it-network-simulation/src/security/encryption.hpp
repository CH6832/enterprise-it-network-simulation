#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <string>
#include <stdexcept>

/**
 * @brief A class that simulates encryption and decryption of messages.
 */
class Encryption {
public:
    /**
     * @brief Constructor for Encryption.
     */
    Encryption();

    /**
     * @brief Destructor for Encryption.
     */
    ~Encryption();

    /**
     * @brief Encrypts a given plaintext message.
     * @param plaintext The message to encrypt.
     * @return The encrypted message.
     * @throws std::invalid_argument if the plaintext is empty.
     */
    std::string encrypt(const std::string& plaintext);

    /**
     * @brief Decrypts a given ciphertext message.
     * @param ciphertext The message to decrypt.
     * @return The decrypted message.
     * @throws std::invalid_argument if the ciphertext is empty.
     */
    std::string decrypt(const std::string& ciphertext);

private:
    std::string key; /**< Encryption key for the encryption and decryption */

    /**
     * @brief Generates a mock encryption key.
     */
    void generateKey();
};

#endif // ENCRYPTION_HPP
