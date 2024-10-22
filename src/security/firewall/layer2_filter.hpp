#ifndef LAYER2FILTER_HPP
#define LAYER2FILTER_HPP

#include <iostream>

/**
 * @brief Simulates Layer 2 filtering for the firewall.
 */
class Layer2Filter {
public:
    /**
     * @brief Filters traffic at OSI Layer 2.
     * 
     * This method simulates the filtering of network traffic
     * to ensure only permitted data packets are forwarded.
     */
    void filterTraffic();
};

#endif // LAYER2FILTER_HPP
