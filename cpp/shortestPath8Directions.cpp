#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <iostream>

int shortestPathBinaryMatrix(std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    std::set<std::pair<int, int>> traversed;
    std::queue<std::tuple<int, int, int>> queue;
    queue.push({0, 0, 0});

    while (queue.size() > 0) {
        auto [row, col, distance] = queue.front();
        std::pair<int, int> position{row, col};
        queue.pop();

        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 1)
            continue;
        
        if (traversed.find(position) == traversed.end()) {
            traversed.insert(position);
            int dist = distance + 1;

            if (row == n - 1 && col == m - 1)
                return dist;
            
            queue.push({row + 1, col + 1, dist});
            queue.push({row + 1, col - 1, dist});
            queue.push({row - 1, col + 1, dist});
            queue.push({row - 1, col - 1, dist});
            queue.push({row + 1, col, dist});
            queue.push({row, col + 1, dist});
            queue.push({row - 1, col, dist});
            queue.push({row, col - 1, dist});
        }
    }

    return -1;
}

int main() {
    std::vector<std::vector<int>> grid{{0, 1}, {1, 0}};
    std::cout << shortestPathBinaryMatrix(grid) << '\n';
}