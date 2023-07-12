#include <vector>
#include <utility>
#include <unordered_set>
#include <iostream>

constexpr int IBIT_LEN = 5;

using Cell = std::pair<int, int>;

/**
 * Cell type enumeration for best practices.
 */
enum CellType {
    Obstacle = -1,
    Empty = 0,
    Start = 1,
    End = 2
};

/**
 * A grid container struct to reduce the number of parameters passed to out recursive function.
 */
struct Grid {
    const std::vector<std::vector<int>> &grid;
    std::unordered_set<int> visited;
    size_t cellCount;
    const int n;
    const int m;
    Cell start;

    Grid(const std::vector<std::vector<int>> &grid):
        grid(grid),
        cellCount(0),
        n(grid.size()),
        m(grid[0].size()) {

        /**
         * Count number of traversable cells and find start position.
         */
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->m; j++) {

                switch (static_cast<CellType>(grid[i][j])) {
                    case CellType::Start:
                        this->start = std::make_pair(i, j);
                    case CellType::End:
                    case CellType::Empty:
                        this->cellCount++;
                        break;
                    default: {}
                }
            }
        }

    }

    /**
     * Find if the cell represented by the given bitmask has been visited.
     */
    inline bool isVisited(int bitmask) {
        return this->visited.find(bitmask) != visited.end();
    }

    /**
     * Visit the cell represented by the given bitmask.
     */
    inline void visit(int bitmask) {
        this->visited.insert(bitmask);
    }

    /**
     * Remove the cell represented by the given bitmask from the set of visited cells.
     */
    inline void backtrack(int bitmask) {
        this->visited.erase(bitmask);
    }

    /**
     * Find if all cells except the end cell have been visited.
     */
    inline bool visitedAll() {
        return this->visited.size() == cellCount - 1;
    }
};

/**
 * Find if indexes i and j are not in the grid.
 */
inline bool notInRange(int i, int j, int n, int m) {
    return i < 0 || j < 0 || i >= n || j >= m;
}

/**
 * Find the number of unique paths from the current position that traverse the entire grid.
 */
int uniquePaths(Grid &grid, int i, int j) {
    // Return if i and j are not in the grid.
    if (notInRange(i, j, grid.n, grid.m))
        return 0;
    
    int bitmask = i + (j << IBIT_LEN);

    // Return if grid[i][j] has already been visited.
    if (grid.isVisited(bitmask))
        return 0;

    switch (static_cast<CellType>(grid.grid[i][j])) {
        case CellType::End: {}
            // If grid[i][j] is an end cell return 1 if all cells have been visited, otherwise return 0.
            if (grid.visitedAll())
                return 1;
        case CellType::Obstacle:
            // Path is not valid.
            return 0;
        default: {
            // If grid[i][j] is an empty cell set [i, j] as visited and visit the cells located one position up, down, left and right from the current cell..
            grid.visit(bitmask);
            int down = uniquePaths(grid, i + 1, j);
            int up = uniquePaths(grid, i - 1, j);
            int right = uniquePaths(grid, i, j + 1);
            int left = uniquePaths(grid, i, j - 1);
            grid.backtrack(bitmask);

            return down + up + right + left;
        }
    }
}

/**
 * Find the number of unique paths from the current position that traverse the entire grid.
 */
int uniquePathsIII(std::vector<std::vector<int>> &grid) {
    Grid myGrid(grid);
    auto [i, j] = myGrid.start;

    return uniquePaths(myGrid, i, j);
}

int main() {
    std::vector<std::vector<int>> nums{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    std::cout << uniquePathsIII(nums) << '\n';
}