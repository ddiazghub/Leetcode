#include <algorithm>
#include <memory>
#include <optional>
#include <unordered_set>
#include <vector>
#include <map>

struct TreeNode {
    static std::unique_ptr<TreeNode> null;

    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    std::unordered_set<int> dependencies;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int data, TreeNode *parent, std::unordered_set<int> dependencies) : data(data), left(nullptr), right(nullptr), parent(parent), dependencies(dependencies) {}

    inline TreeNode *next(int value) {
        if (value > this->data)
            return this->right;
        else
            return this->left;
    }

    void add(int data) {
        std::unordered_set<int> dependencies;
        TreeNode *current = this;
        TreeNode *next = current->next(current->data);

        while (next != nullptr) {
            dependencies.insert(current->data);
            current = next;
            next = next->next(data);
        }

        dependencies.insert(current->data);
        TreeNode *node = new TreeNode(data, current, std::move(dependencies));
        
        if (data > current->data)
            current->right = node;
        else
            current->left = node;
    }

    static void fillDependencies(TreeNode *current, std::map<int, std::unordered_set<int>> &dependencies) {
        if (current == nullptr)
            return;

        fillDependencies(current->left, dependencies);
        fillDependencies(current->right, dependencies);
        dependencies.insert({current->data, std::move(current->dependencies)});
    }
};

int numOfWays(std::vector<int> &nums) {
    int size = nums.size();
    TreeNode root(nums[0]);

    for (auto &num : nums)
        root.add(num);

    std::map<int, std::unordered_set<int>> dependencies;
    TreeNode::fillDependencies(&root, dependencies);
}

int main() {

}
