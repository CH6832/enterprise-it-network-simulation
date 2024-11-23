#ifndef SMURF_ATTACK_HPP
#define SMURF_ATTACK_HPP

#include <string>

/**
 * @brief Simulates the detection and prevention of Smurf attacks.
 */
class SmurfAttack {
public:
    SmurfAttack();
    ~SmurfAttack();

    /**
     * @brief Simulates detecting a Smurf attack.
     * @param sourceIp Source IP of the potential attack.
     * @return True if attack is detected, false otherwise.
     */
    bool detectAttack(const std::string& sourceIp);

    /**
     * @brief Prevents further damage from a Smurf attack.
     */
    void mitigateAttack();

private:
    bool isUnderAttack; /**< Status of ongoing attack */
};

#endif // SMURF_ATTACK_HPP
