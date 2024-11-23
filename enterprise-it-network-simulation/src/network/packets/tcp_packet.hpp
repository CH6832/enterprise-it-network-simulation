#ifndef TCP_PACKET_HPP
#define TCP_PACKET_HPP

#include <string>

/**
 * @brief Simulates a TCP packet.
 */
class TcpPacket {
public:
    TcpPacket(const std::string& srcIp, const std::string& destIp, int dataSize);
    ~TcpPacket();

    /**
     * @brief Gets the source IP address.
     * @return Source IP as a string.
     */
    std::string getSourceIP() const;

    /**
     * @brief Gets the destination IP address.
     * @return Destination IP as a string.
     */
    std::string getDestinationIP() const;

    /**
     * @brief Gets the size of the data payload.
     * @return Data size in bytes.
     */
    int getDataSize() const;

private:
    std::string sourceIP; /**< Source IP address */
    std::string destinationIP; /**< Destination IP address */
    int dataSize; /**< Size of the data payload */
};

#endif // TCP_PACKET_HPP
