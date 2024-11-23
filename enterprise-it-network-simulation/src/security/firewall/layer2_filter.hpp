#ifndef LAYER2_FILTER_HPP
#define LAYER2_FILTER_HPP

#include <string>
#include <vector>

/**
 * @brief Layer 2 filtering for network traffic.
 */
class Layer2Filter {
public:
    Layer2Filter();
    ~Layer2Filter();

    /**
     * @brief Applies a MAC address filter.
     * @param mac The MAC address to filter.
     */
    void applyMACFilter(const std::string& mac);

    /**
     * @brief Clears all MAC address filters.
     */
    void clearFilters();

    /**
     * @brief Checks if a MAC address is allowed.
     * @param mac The MAC address to check.
     * @return True if allowed, false otherwise.
     */
    bool isMACAllowed(const std::string& mac) const;

private:
    std::vector<std::string> macFilters; /**< List of MAC filters */
};

#endif // LAYER2_FILTER_HPP
