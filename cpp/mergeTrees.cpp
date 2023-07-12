#include <vector>
#include <array>

/**
 * Node of a binary tree.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Merge 2 binary trees.
 */
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return nullptr;

    TreeNode *outHead = new TreeNode;
    std::vector<std::array<TreeNode *, 3>> stack{{root1, root2, outHead}};

    while (stack.size() > 0) {
        auto [node1, node2, outNode] = stack.back();
        stack.pop_back();

        if (node1 && node2) {
            outNode->val = node1->val + node2->val;

            if (node1->left || node2->left) {
                outNode->left = new TreeNode;
                stack.push_back({node1->left, node2->left, outNode->left});
            }
            
            if (node1->right || node2->right) {
                outNode->right = new TreeNode;
                stack.push_back({node1->right, node2->right, outNode->right});
            }
        } else if (node1) {
            outNode->val = node1->val;
            outNode->left = node1->left;
            outNode->right = node1->right;
        } else if (node2) {
            outNode->val = node2->val;
            outNode->left = node2->left;
            outNode->right = node2->right;
        }
    }

    return outHead;
}

int main() {

}