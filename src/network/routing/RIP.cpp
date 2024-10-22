#include "RIP.hpp"
#include <limits>
#include <stdexcept>
#include <algorithm>

RIP::RIP(const std::string& routerId) : routerId_(routerId) {
    std::cout << "RIP router " << routerId_ << " initialized." << std::endl;
}

void RIP::addNeighbor(const std::string& neighborId, int hopCount) {
    if (hopCount <= 0) {
        throw std::invalid_argument("Hop count must be greater than zero.");
    }

    // Add the neighbor with the given hop count (distance)
    neighbors_[neighborId] = hopCount;
    routingTable_[neighborId] = hopCount;

    std::cout << "Neighbor " << neighborId << " added with hop count " << hopCount << "." << std::endl;
}

void RIP::startRouting() {
    std::cout << "Starting RIP routing process for Router " << routerId_ << "..." << std::endl;

    // Simulate sending initial routing updates to neighbors
    sendRoutingUpdates();
    
    // Print the initial routing table
    printRoutingTable();
}

void RIP::sendRoutingUpdates() {
    std::cout << "Sending routing updates from Router " << routerId_ << " to neighbors..." << std::endl;

    // Simulate sending the routing table to all neighbors
    for (const auto& neighbor : neighbors_) {
        const std::string& neighborId = neighbor.first;
        std::cout << "Routing update sent to " << neighborId << "." << std::endl;

        // In a real-world scenario, here we would send `routingTable_` to the neighbor.
    }
}

void RIP::receiveRoutingUpdate(const std::string& neighborId, 
                               const std::unordered_map<std::string, int>& neighborRoutingTable) {
    std::cout << "Received routing update from " << neighborId << "." << std::endl;

    // Update the routing table based on the neighbor's information
    for (const auto& entry : neighborRoutingTable) {
        const std::string& destination = entry.first;
        int hopCount = entry.second;

        // The hop count to the destination via the neighbor
        int newHopCount = neighbors_[neighborId] + hopCount;

        // Update the routing table if this path is better (shorter hop count)
        updateRoutingTable(destination, newHopCount);
    }
}

void RIP::updateRoutingTable(const std::string& destination, int newHopCount) {
    auto it = routingTable_.find(destination);
    if (it == routingTable_.end() || newHopCount < it->second) {
        // If destination is not in the table, or the new path is shorter, update the entry
        routingTable_[destination] = newHopCount;
        std::cout << "Updated route to " << destination << " with hop count " << newHopCount << "." << std::endl;
    }
}

void RIP::printRoutingTable() const {
    std::cout << "Routing Table for Router " << routerId_ << ":" << std::endl;
    for (const auto& entry : routingTable_) {
        std::cout << "  Destination: " << entry.first << ", Hop Count: " << entry.second << std::endl;
    }
}
