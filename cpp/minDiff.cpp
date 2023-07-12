#include <set>
#include <vector>
#include <iostream>
#include <ostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
int getMinimumDifference(TreeNode* root) {
    std::cout << "Hello" << '\n';
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 9};

    for (auto &num : nums) {
        std::cout << num << '\n';
    }
}

int main() {

}
