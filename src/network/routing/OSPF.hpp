#ifndef OSPF_HPP
#define OSPF_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <limits>

/**
 * @class OSPF
 * @brief Simulates the Open Shortest Path First (OSPF) routing protocol.
 * 
 * OSPF is a link-state routing protocol used in IP networks. It calculates the
 * shortest path based on the Dijkstra algorithm and maintains a link-state database (LSDB).
 * This class simulates key OSPF behaviors, including routing, managing OSPF areas,
 * and handling link-state advertisements.
 */
class OSPF {
public:
    /**
     * @brief Constructor for the OSPF class.
     * 
     * Initializes OSPF with the router's ID and default area.
     * 
     * @param routerId The unique ID of the router in the OSPF domain.
     * @param areaId The OSPF area this router belongs to (default is 0).
     */
    OSPF(const std::string& routerId, int areaId = 0);

    /**
     * @brief Adds a link between two routers with a specified cost.
     * 
     * This simulates a connection between two OSPF routers with the given link cost.
     * 
     * @param destinationRouterId The ID of the destination router.
     * @param cost The cost of the link.
     */
    void addLink(const std::string& destinationRouterId, int cost);

    /**
     * @brief Starts the OSPF routing process.
     * 
     * Simulates the OSPF routing process, including link-state advertisement (LSA)
     * exchange and shortest path calculation using Dijkstra's algorithm.
     */
    void startRouting();

    /**
     * @brief Prints the routing table.
     * 
     * Displays the current routing table for this OSPF instance, showing the
     * shortest paths to all other routers in the network.
     */
    void printRoutingTable() const;

private:
    std::string routerId_;  ///< Unique identifier for the OSPF router
    int areaId_;            ///< OSPF area to which this router belongs
    std::unordered_map<std::string, std::unordered_map<std::string, int>> linkStateDatabase_; ///< Link-State Database (LSDB)
    std::unordered_map<std::string, int> routingTable_;  ///< Stores the shortest paths (destination router, cost)

    /**
     * @brief Runs Dijkstra's algorithm to calculate the shortest paths.
     * 
     * This method computes the shortest paths from this router to all other routers
     * based on the current link-state database (LSDB).
     */
    void runDijkstra();
};

#endif // OSPF_HPP
