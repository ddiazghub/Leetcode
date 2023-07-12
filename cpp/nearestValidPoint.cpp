#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

/**
 * Find the manhattan distane between 2 points.
 */
inline int manhattanDist(std::vector<int> &point1, std::vector<int> &point2) {
    return std::abs(point2[0] - point1[0]) + std::abs(point2[1] - point1[1]);
}

/**
 * Find Nearest Point That Has the Same X or Y Coordinate
 */
int nearestValidPoint(int x, int y, std::vector<std::vector<int>>& points) {
    std::vector<int> origin{x, y};
    std::pair<int, int> closest = std::make_pair(-1, std::numeric_limits<int>::max());
    int n = points.size();

    for (int i = 0; i < n; i++) {
        auto &point = points[i];

        if (point[0] == x || point[1] == y) {
            int distance = manhattanDist(origin, point);

            if (distance < closest.second)
                closest = std::make_pair(i, distance);
        }
    }

    return closest.first;
}