#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Return max depth of the subtree that has the current node as root.
 */
int maxDepth(TreeNode *node, int depth) {
    if (node == nullptr)
        return depth;

    int left = maxDepth(node->left, depth + 1);
    int right = maxDepth(node->right, depth + 1);

    return std::max(left, right);
}

/**
 * Return max depth of a tree.
 */
int maxDepth(TreeNode *root) {
    return maxDepth(root, 0);
}

int main() {

}