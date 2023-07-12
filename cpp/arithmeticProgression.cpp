#include <vector>
#include <algorithm>

/**
 * An arithmetic progression can be made with an array.
 */
bool canMakeArithmeticProgression(std::vector<int> &arr) {
    int n = arr.size();
    std::sort(arr.begin(), arr.end());
    int step = arr[1] - arr[0];

    for (int i = 2; i < n; i++) {
        if (arr[i] - arr[i - 1] != step)
            return false;
    }

    return true;
}

int main() {

}