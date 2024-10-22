#include "OSPF.hpp"
#include <queue>
#include <functional>
#include <limits>
#include <stdexcept>

OSPF::OSPF(const std::string& routerId, int areaId)
    : routerId_(routerId), areaId_(areaId) {
    std::cout << "OSPF Router " << routerId_ << " created in Area " << areaId_ << "." << std::endl;
}

void OSPF::addLink(const std::string& destinationRouterId, int cost) {
    if (cost < 0) {
        throw std::invalid_argument("Link cost cannot be negative.");
    }

    // Add the link in the link-state database (LSDB)
    linkStateDatabase_[routerId_][destinationRouterId] = cost;
    linkStateDatabase_[destinationRouterId][routerId_] = cost; // Assuming bidirectional link

    std::cout << "Link added between " << routerId_ << " and " << destinationRouterId
              << " with cost " << cost << "." << std::endl;
}

void OSPF::startRouting() {
    std::cout << "Starting OSPF routing process for Router " << routerId_ << "..." << std::endl;

    // Run the Dijkstra algorithm to calculate shortest paths
    runDijkstra();

    // Print the routing table after calculation
    printRoutingTable();
}

void OSPF::runDijkstra() {
    std::cout << "Running Dijkstra's algorithm to calculate shortest paths..." << std::endl;

    // Initialize the distance to all nodes as infinity
    std::unordered_map<std::string, int> distances;
    for (const auto& node : linkStateDatabase_) {
        distances[node.first] = std::numeric_limits<int>::max();
    }

    // Distance to self is zero
    distances[routerId_] = 0;

    // Priority queue for Dijkstra's algorithm (min-heap)
    using PQueue = std::priority_queue<std::pair<int, std::string>, 
                                       std::vector<std::pair<int, std::string>>, 
                                       std::greater<std::pair<int, std::string>>>;
    PQueue pq;
    pq.push({0, routerId_});

    // Dijkstra's algorithm main loop
    while (!pq.empty()) {
        auto [currentDist, currentRouter] = pq.top();
        pq.pop();

        // Visit each neighbor of the current router
        for (const auto& neighbor : linkStateDatabase_[currentRouter]) {
            const std::string& neighborId = neighbor.first;
            int linkCost = neighbor.second;

            int newDist = currentDist + linkCost;
            if (newDist < distances[neighborId]) {
                distances[neighborId] = newDist;
                pq.push({newDist, neighborId});
            }
        }
    }

    // Update the routing table with the shortest path results
    routingTable_ = distances;
}

void OSPF::printRoutingTable() const {
    std::cout << "OSPF Routing Table for Router " << routerId_ << ":" << std::endl;
    for (const auto& entry : routingTable_) {
        std::cout << "  Destination: " << entry.first << ", Cost: " << entry.second << std::endl;
    }
}
