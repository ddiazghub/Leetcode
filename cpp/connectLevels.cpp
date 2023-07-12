#include <cstddef>
#include <queue>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root) {
    if (root == nullptr)
        return nullptr;
    
    std::queue<Node *> queue;
    queue.push(root);
    Node *last = nullptr;
    int level = 0;
    int nextLevel = 1;

    while (queue.size() > 0) {
        Node *node = queue.front();
        queue.pop();
        node->next = last;

        if (node->left) {
            queue.push(node->right);
            queue.push(node->left);
        }

        nextLevel--;

        if (nextLevel == 0) {
            level++;
            nextLevel = 1 << level;
            last = nullptr;
        } else {
            last = node;
        }
    }

    return root;
}

int main() {
    Node a(7);
    Node b(6);
    Node c(5);
    Node d(4);
    Node e(3, &b, &a, nullptr);
    Node f(2, &d, &c, nullptr);
    Node g(1, &f, &e, nullptr);
    connect(&g);
}