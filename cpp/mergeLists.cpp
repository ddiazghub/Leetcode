#include <vector>
#include <limits>

/**
 * Singly linked list node.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Find the indexes of the nodes with the minimum value in a lists of nodes.
 */
std::vector<int> minimums(std::vector<ListNode *> &nodes) {
    int minValue = std::numeric_limits<int>::max();
    std::vector<int> mins;
    int n = nodes.size();

    for (int i = 0; i < n; i++) {
        ListNode *node = nodes[i];

        if (node != nullptr) {
            // If the node is smaller than the min value clear the min values array before adding it, if it is equal just add it.
            if (node->val < minValue) {
                mins.clear();
                mins.push_back(i);
                minValue = node->val;
            } else if (node->val == minValue) {
                mins.push_back(i);
                minValue = node->val;
            }
        }
    }

    return mins;
}

/**
 * Merge K sorted singly linked lists into a single list.
 */
ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    ListNode fakeHead;
    ListNode *tail = &fakeHead;
    std::vector<int> toMerge{0};

    while (toMerge.size() > 0) {
        toMerge = minimums(lists);

        // Merge the nodes with the min value into the output list.
        for (int i: toMerge) {
            tail->next = lists[i];
            tail = tail->next;
            lists[i] = lists[i]->next;
        }
    }

    return fakeHead.next;
}

int main() {
    ListNode h(6);
    ListNode g(2, &h);
    ListNode f(4);
    ListNode e(3, &f);
    ListNode d(1, &e);
    ListNode c(5);
    ListNode b(4, &c);
    ListNode a(1, &b);

    std::vector<ListNode *> lists{&a, &d, &g};
    mergeKLists(lists);
}