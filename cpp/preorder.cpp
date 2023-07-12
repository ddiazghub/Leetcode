#include <vector>

/**
 * A node of an n-ary tree.
 */
class Node {
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

/**
 * Traverse an n-ary tree in preorder.
 */
std::vector<int> preorder(Node *root) {
    std::vector<int> traversal;

    if (root != nullptr) {
        std::vector<Node *> stack{root};

        while (stack.size() > 0) {
            Node *node = stack.back();
            stack.pop_back();
            traversal.push_back(node->val);

            for (int i = node->children.size() - 1; i > -1; i--)
                stack.push_back(node->children[i]);
        }   
    }

    return traversal;
}

int main() {

}