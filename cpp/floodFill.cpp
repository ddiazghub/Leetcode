#include <vector>
#include <queue>
#include <utility>
#include <set>

/**
 * Replace all pixels continuosly connected with [sr, sc] that share the same color with the target color.
 */
void floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int original, int color) {
    int rows = image.size();
    int cols = image[0].size();

    if (sr >= rows || sr < 0 || sc >= cols || sc < 0 || image[sr][sc] != original)
        return;

    image[sr][sc] = color;
    floodFill(image, sr + 1, sc, original, color);
    floodFill(image, sr - 1, sc, original, color);
    floodFill(image, sr, sc + 1, original, color);
    floodFill(image, sr, sc - 1, original, color);
}

/**
 * Replace all pixels continuosly connected with [sr, sc] that share the same color with the target color.
 */
std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int color) {
    std::vector<std::vector<int>> img(image);
    std::set<std::pair<int, int>> traversed;
    std::queue<std::pair<int, int>> next;
    auto start = std::make_pair(sr, sc);
    next.push(start);
    int original = image[sr][sc];
    int n = image.size();
    int m = image[0].size();

    while (next.size() > 0) {
        auto nextPixel = next.front();
        auto [i, j] = nextPixel;
        next.pop();

        if (traversed.find(nextPixel) != traversed.end())
            continue;
        
        if (i > -1 && i < n && j > -1 && j < m && img[i][j] == original) {
            traversed.insert(nextPixel);
            img[i][j] = color;

            next.push(std::make_pair(i + 1, j));
            next.push(std::make_pair(i - 1, j));
            next.push(std::make_pair(i, j + 1));
            next.push(std::make_pair(i, j - 1));
        }
    }

    return img;
}

int main() {
    std::vector<std::vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    floodFill(image, 1, 1, 2);
}