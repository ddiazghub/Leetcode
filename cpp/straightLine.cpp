#include <vector>
#include <algorithm>
#include <limits>

/**
 * Find the slope of the line that connects point1 and point2.
 */
inline double slope(std::vector<int> &point1, std::vector<int> &point2) {
    double xDistance = point2[0] - point1[0];

    return xDistance == 0.0 ? std::numeric_limits<float>::infinity() : (point2[1] - point1[1]) / xDistance;
}

/**
 * Check if the points in the vector create a straight line.
 */
bool checkStraightLine(std::vector<std::vector<int>> &coordinates) {
    int n = coordinates.size();
    double firstSlope = slope(coordinates[0], coordinates[1]);

    for (int i = 2; i < n; i++) {
        if (slope(coordinates[i - 1], coordinates[i]) != firstSlope)
            return false;
    }

    return true;
}

int main() {

}