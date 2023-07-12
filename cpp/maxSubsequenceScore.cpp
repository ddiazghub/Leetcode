#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

long long maxScore(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
    int n = nums1.size();
    std::vector<std::pair<int, int>> combined;

    for (int i = 0; i < n; i++)
        combined.push_back(std::make_pair(nums2[i], nums1[i]));

    std::sort(combined.begin(), combined.end(), std::greater<std::pair<int, int>>());
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    long long sum = 0L;

    for (int i = 0; i < k; i++) {
        int value = combined[i].second;
        sum += value;
        minHeap.push(value);
    }

    long long max = sum * combined[k - 1].first;

    for (int i = k; i < n; i++) {
        sum -= minHeap.top();
        minHeap.pop();
        int value = combined[i].second;
        sum += value;
        minHeap.push(value);
        max = std::max(max, sum * combined[i].first);
    }

    return max;
}

int main() {

}