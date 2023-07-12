#include <vector>
#include <numeric>
#include <algorithm>

/**
 * Find the maximum wealth in a list of customers and a list of the bank accounts held by those customers.
 */
int maximumWealth(std::vector<std::vector<int>> &accounts) {
    int n = accounts.size();
    int m = accounts[0].size();
    int max = 0;

    for (auto &customer: accounts) {
        int wealth = std::accumulate(customer.cbegin(), customer.cend(), 0);
        max = std::max(max, wealth);
    }

    return max;
}