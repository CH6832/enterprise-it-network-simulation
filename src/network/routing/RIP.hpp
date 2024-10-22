#ifndef RIP_HPP
#define RIP_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

/**
 * @class RIP
 * @brief Simulates the Routing Information Protocol (RIP) used for network routing.
 * 
 * RIP is a distance-vector routing protocol that determines the best path to a destination
 * based on hop count. It periodically shares routing updates with neighboring routers.
 */
class RIP {
public:
    /**
     * @brief Constructor for the RIP class.
     * 
     * Initializes the router with a unique ID.
     * 
     * @param routerId The unique identifier for the router running RIP.
     */
    RIP(const std::string& routerId);

    /**
     * @brief Adds a neighboring router and defines the cost (hop count) to reach it.
     * 
     * This simulates adding a directly connected neighbor to the RIP network.
     * 
     * @param neighborId The ID of the neighboring router.
     * @param hopCount The hop count (distance) to the neighboring router.
     */
    void addNeighbor(const std::string& neighborId, int hopCount);

    /**
     * @brief Starts the RIP routing process.
     * 
     * Simulates RIP routing, including periodic routing updates, calculation of the
     * shortest paths, and handling of distance-vector updates.
     */
    void startRouting();

    /**
     * @brief Simulates sending routing updates to neighbors.
     * 
     * Sends the current routing table to all directly connected neighbors.
     */
    void sendRoutingUpdates();

    /**
     * @brief Processes received routing updates from neighboring routers.
     * 
     * This method handles distance-vector updates from neighbors, updating the routing table accordingly.
     * 
     * @param neighborId The ID of the router sending the update.
     * @param neighborRoutingTable The routing table of the neighbor.
     */
    void receiveRoutingUpdate(const std::string& neighborId, 
                              const std::unordered_map<std::string, int>& neighborRoutingTable);

    /**
     * @brief Prints the current routing table.
     * 
     * Displays the shortest path (in terms of hop count) to each reachable router.
     */
    void printRoutingTable() const;

private:
    std::string routerId_;  ///< Unique identifier for the router running RIP
    std::unordered_map<std::string, int> routingTable_;  ///< The router's own routing table (destination, hop count)
    std::unordered_map<std::string, int> neighbors_;     ///< Directly connected neighbors (neighbor ID, hop count)

    /**
     * @brief Updates the routing table with new paths based on received updates.
     * 
     * Handles the RIP rule: if a new path is shorter than the existing one, update it.
     */
    void updateRoutingTable(const std::string& destination, int newHopCount);
};

#endif // RIP_HPP
