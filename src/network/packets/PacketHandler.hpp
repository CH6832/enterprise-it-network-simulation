#ifndef PACKET_HANDLER_HPP
#define PACKET_HANDLER_HPP

#include <string>
#include <vector>
#include <stdexcept>

/**
 * @class PacketHandler
 * @brief Handles and processes network packets.
 * 
 * This class is responsible for parsing, validating, and processing
 * network packets. It supports packet analysis, extraction of headers,
 * and managing packet payloads.
 */
class PacketHandler {
public:
    /**
     * @brief Processes an incoming network packet.
     * 
     * This function takes a raw packet (as a byte vector) and handles
     * the packet by parsing its contents, validating its structure, 
     * and triggering appropriate actions.
     * 
     * @param packet The raw packet data as a vector of bytes.
     * @throws std::invalid_argument If the packet is invalid.
     */
    void handlePacket(const std::vector<uint8_t>& packet);

private:
    /**
     * @brief Validates the structure and integrity of the packet.
     * 
     * This function checks if the packet meets basic criteria such as
     * having the correct header, length, and checksum.
     * 
     * @param packet The raw packet data.
     * @return True if the packet is valid, false otherwise.
     */
    bool validatePacket(const std::vector<uint8_t>& packet);

    /**
     * @brief Extracts header information from the packet.
     * 
     * This function reads the header fields such as protocol type,
     * source and destination addresses, and packet length.
     * 
     * @param packet The raw packet data.
     * @return A string containing the extracted header information.
     */
    std::string extractHeader(const std::vector<uint8_t>& packet);

    /**
     * @brief Extracts the payload data from the packet.
     * 
     * This function extracts the payload or body of the packet, which
     * typically contains the actual data being transmitted.
     * 
     * @param packet The raw packet data.
     * @return A vector of bytes containing the packet's payload.
     */
    std::vector<uint8_t> extractPayload(const std::vector<uint8_t>& packet);

    /**
     * @brief Logs the packet details for debugging or auditing.
     * 
     * Logs the packet's header information and payload details.
     * This helps in tracking and troubleshooting packet handling issues.
     * 
     * @param packet The raw packet data.
     */
    void logPacketDetails(const std::vector<uint8_t>& packet);
};

#endif // PACKET_HANDLER_HPP
