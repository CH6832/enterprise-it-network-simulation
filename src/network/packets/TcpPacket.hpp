#ifndef TCP_PACKET_HPP
#define TCP_PACKET_HPP

#include <string>
#include <vector>
#include <cstdint>

/**
 * @class TcpPacket
 * @brief Simulates a TCP packet with headers, payload, and error checking.
 * 
 * This class represents a basic structure for a TCP packet, including
 * fields for source and destination ports, sequence numbers, flags,
 * and payload data. It includes methods to simulate packet transmission
 * and error handling.
 */
class TcpPacket {
public:
    /**
     * @brief Constructor for TcpPacket class.
     * 
     * Initializes a TCP packet with source and destination ports, as well as payload data.
     * 
     * @param srcPort The source port of the TCP packet.
     * @param destPort The destination port of the TCP packet.
     * @param payload The data to be transmitted in the packet.
     */
    TcpPacket(uint16_t srcPort, uint16_t destPort, const std::vector<uint8_t>& payload);

    /**
     * @brief Transmits the TCP packet.
     * 
     * Simulates the process of transmitting a TCP packet over a network. This includes
     * displaying the packet's details and simulating the transmission process.
     * 
     * @throws std::runtime_error If an error occurs during transmission.
     */
    void transmit();

    /**
     * @brief Validates the TCP packet.
     * 
     * Checks for potential issues in the TCP packet, such as invalid headers or
     * missing payload data.
     * 
     * @return True if the packet is valid, false otherwise.
     */
    bool validatePacket() const;

private:
    uint16_t srcPort_;              ///< Source port
    uint16_t destPort_;             ///< Destination port
    uint32_t sequenceNumber_;       ///< Sequence number (for simplicity, initialize to 0)
    uint32_t ackNumber_;            ///< Acknowledgment number (for simplicity, initialize to 0)
    uint8_t flags_;                 ///< TCP flags (SYN, ACK, etc.)
    std::vector<uint8_t> payload_;  ///< Packet payload (data)

    /**
     * @brief Logs details of the TCP packet.
     * 
     * Outputs the TCP packet's header and payload in a human-readable format.
     */
    void logPacketDetails() const;
};

#endif // TCP_PACKET_HPP
