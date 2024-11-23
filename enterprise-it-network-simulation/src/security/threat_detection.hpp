#ifndef THREAT_DETECTION_HPP
#define THREAT_DETECTION_HPP

#include <string>
#include <vector>

/**
 * @brief Simulates threat detection on a network.
 */
class ThreatDetection {
public:
    ThreatDetection();
    ~ThreatDetection();

    /**
     * @brief Scans the network for threats.
     * @return List of detected threats.
     */
    std::vector<std::string> scanForThreats() const;

    /**
     * @brief Adds a simulated threat to the database.
     * @param threatName Name of the threat.
     */
    void addThreat(const std::string& threatName);

private:
    std::vector<std::string> threats; /**< Simulated list of known threats */
};

#endif // THREAT_DETECTION_HPP
