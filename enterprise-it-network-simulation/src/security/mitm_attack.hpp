#ifndef MITM_ATTACK_HPP
#define MITM_ATTACK_HPP

#include <string>

/**
 * @brief Simulates detection and prevention of Man-in-the-Middle (MITM) attacks.
 */
class MitmAttack {
public:
    MitmAttack();
    ~MitmAttack();

    /**
     * @brief Simulates detecting a MITM attack.
     * @param victimIp IP address of the victim.
     * @return True if attack is detected, false otherwise.
     */
    bool detectAttack(const std::string& victimIp);

    /**
     * @brief Simulates preventing a detected MITM attack.
     */
    void preventAttack();

private:
    bool isAttackDetected; /**< Status of MITM attack detection */
};

#endif // MITM_ATTACK_HPP
