#ifndef PACKET_HANDLER_HPP
#define PACKET_HANDLER_HPP

#include <string>
#include <memory>
#include <spdlog/spdlog.h>
#include <stdexcept>
#include <vector>

/**
 * @brief A class to simulate the handling of network packets.
 */
class PacketHandler {
public:
    /**
     * @brief Constructor for PacketHandler.
     */
    PacketHandler();

    /**
     * @brief Destructor for PacketHandler.
     */
    ~PacketHandler();

    /**
     * @brief Handles a TCP packet.
     * @param packet The packet data to handle.
     * @throws std::invalid_argument if the packet is invalid.
     */
    void handleTcpPacket(const std::vector<uint8_t>& packet);

    /**
     * @brief Handles a UDP packet.
     * @param packet The packet data to handle.
     * @throws std::invalid_argument if the packet is invalid.
     */
    void handleUdpPacket(const std::vector<uint8_t>& packet);

    /**
     * @brief Validates a packet.
     * @param packet The packet data to validate.
     * @return true if the packet is valid, false otherwise.
     */
    bool validatePacket(const std::vector<uint8_t>& packet) const;

private:
    void processPacket(const std::vector<uint8_t>& packet, const std::string& protocol);
    bool isValidPacketSize(const std::vector<uint8_t>& packet) const;
};

#endif // PACKET_HANDLER_HPP
