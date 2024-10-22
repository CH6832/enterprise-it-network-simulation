#ifndef UDP_PACKET_HPP
#define UDP_PACKET_HPP

#include <string>
#include <vector>
#include <cstdint>

/**
 * @class UdpPacket
 * @brief Simulates a UDP packet with headers, payload, and error checking.
 * 
 * This class models the structure of a UDP packet, including fields
 * like source and destination ports, length, checksum, and the actual data.
 * It provides methods to simulate transmission, validate packet data,
 * and handle error detection via checksum computation.
 */
class UdpPacket {
public:
    /**
     * @brief Constructor for UdpPacket class.
     * 
     * Initializes a UDP packet with source and destination ports and payload data.
     * 
     * @param srcPort The source port of the UDP packet.
     * @param destPort The destination port of the UDP packet.
     * @param payload The data to be transmitted in the packet.
     */
    UdpPacket(uint16_t srcPort, uint16_t destPort, const std::vector<uint8_t>& payload);

    /**
     * @brief Transmits the UDP packet.
     * 
     * Simulates the process of transmitting a UDP packet over a network. This includes
     * displaying the packet's details and simulating the transmission process.
     * 
     * @throws std::runtime_error If an error occurs during transmission.
     */
    void transmit();

    /**
     * @brief Validates the UDP packet.
     * 
     * Ensures that the UDP packet contains valid headers, payload, and checksum.
     * 
     * @return True if the packet is valid, false otherwise.
     */
    bool validatePacket() const;

    /**
     * @brief Computes and returns the checksum of the UDP packet.
     * 
     * This method calculates a simple checksum for error detection. In real-world applications,
     * UDP uses a 16-bit checksum to detect errors.
     * 
     * @return The computed checksum.
     */
    uint16_t computeChecksum() const;

private:
    uint16_t srcPort_;              ///< Source port
    uint16_t destPort_;             ///< Destination port
    uint16_t length_;               ///< Length of the UDP packet (header + payload)
    uint16_t checksum_;             ///< Packet checksum for error detection
    std::vector<uint8_t> payload_;  ///< Payload of the UDP packet (data)

    /**
     * @brief Logs details of the UDP packet.
     * 
     * Outputs the UDP packet's header and payload in a human-readable format.
     */
    void logPacketDetails() const;
};

#endif // UDP_PACKET_HPP
