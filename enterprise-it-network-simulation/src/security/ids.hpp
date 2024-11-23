#ifndef IDS_HPP
#define IDS_HPP

#include <string>

/**
 * @brief Simulates an Intrusion Detection System.
 */
class IDS {
public:
    IDS();
    ~IDS();

    /**
     * @brief Analyzes network traffic for intrusion attempts.
     * @param packetData Simulated packet data.
     * @return True if an intrusion is detected, false otherwise.
     */
    bool analyzeTraffic(const std::string& packetData);

    /**
     * @brief Reports detected intrusions.
     */
    void reportIntrusion() const;

private:
    bool intrusionDetected; /**< Status of intrusion detection */
};

#endif // IDS_HPP
