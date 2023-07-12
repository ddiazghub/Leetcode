struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Check if the given node is a leaf node.
 */
inline bool isLeaf(TreeNode *node) {
    return node->left == nullptr && node->right == nullptr;
}

/**
 * Return the sum of all nodes that are leaves and are the left child of another node.
 */
int sumOfLeftLeaves(TreeNode *root) {
    if (root == nullptr)
        return 0;

    int right = sumOfLeftLeaves(root->right);
    
    if (root->left != nullptr && isLeaf(root->left))
        return right + root->left->val;

    return right + sumOfLeftLeaves(root->left);
}