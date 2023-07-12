#include <vector>

/**
 * Find the smallest set of vertices from which all nodes in the graph are reachable.
 */
std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>> &edges) {
    std::vector<bool> hasIncidence(n, false);

    for (auto &edge: edges)
        hasIncidence[edge[1]] = true;

    std::vector<int> setOfNodes;

    for (int i = 0; i < n; i++) {
        if (!hasIncidence[i])
            setOfNodes.push_back(i);
    }

    return setOfNodes;
}

int main() {

}