#include <vector>
#include <algorithm>
#include <queue>

class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> elements;
    int k;

public:
    KthLargest(int k, std::vector<int> &nums) :
        k(k),
        elements(nums.begin(), nums.end()) {}
    
    int add(int val) {
        this->elements.push(val);

        while (this->elements.size() > k)
            this->elements.pop();

        return this->elements.top();
    }
};