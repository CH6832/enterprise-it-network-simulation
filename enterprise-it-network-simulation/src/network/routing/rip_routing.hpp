#ifndef RIP_ROUTING_HPP
#define RIP_ROUTING_HPP

#include <map>
#include <string>

/**
 * @brief Simulates RIP (Routing Information Protocol) for dynamic routing.
 */
class RipRouting {
public:
    RipRouting();
    ~RipRouting();

    /**
     * @brief Adds a route to the routing table.
     * @param destination Destination network.
     * @param nextHop Next hop IP address.
     */
    void addRoute(const std::string& destination, const std::string& nextHop);

    /**
     * @brief Removes a route from the routing table.
     * @param destination Destination network to remove.
     */
    void removeRoute(const std::string& destination);

    /**
     * @brief Gets the next hop for a destination.
     * @param destination Destination network.
     * @return Next hop IP address, or empty if not found.
     */
    std::string getNextHop(const std::string& destination) const;

private:
    std::map<std::string, std::string> routingTable; /**< Routing table for destination-next hop mapping */
};

#endif // RIP_ROUTING_HPP
