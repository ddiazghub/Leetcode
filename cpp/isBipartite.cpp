#include <vector>
#include <iostream>
#include <algorithm>
#include <optional>
#include <unordered_set>

/**
 * Find if a graph is bipartite.
 */
bool isBipartite(std::vector<std::vector<int>> &graph) {
    unsigned int nodes = graph.size();
    std::unordered_set<int> visited;
    std::vector<std::optional<bool>> sets(nodes);
    std::vector<int> stack;

    while (visited.size() < nodes) {
        auto found = std::find_if(sets.cbegin(), sets.cend(), [](auto &node) {
            return node == std::nullopt;
        });

        int index = std::distance(sets.cbegin(), found);
        stack.push_back(index);
        sets[index] = std::make_optional(true);

        while (stack.size() > 0) {
            int next = stack.back();
            stack.pop_back();
            visited.insert(next);
            bool set = sets[next].value();

            for (int node : graph[next]) {
                if (visited.find(node) == visited.end()) {
                    if (sets[node].value_or(!set) == set)
                        return false;
                    
                    sets[node] = std::make_optional(!set);
                    stack.push_back(node);
                }
            }
        }
    }


    return true;
}

int main() {
    std::vector<std::vector<int>> graph{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    isBipartite(graph);
}