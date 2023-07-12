#include <utility>
#include <algorithm>

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
 * Swap the 2 nodes after the given nodes.
 */
inline void swapNexts(ListNode *node1, ListNode *node2) {
    ListNode *temp = node2->next->next;

    if (node1->next == node2) {
        node2->next->next = node1->next;
        node1->next = node2->next;
        node2->next = temp;
    } else {
        node2->next->next = node1->next->next;
        node1->next->next = temp;
        temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
    }
}

/**
 * Swap the k-th node from the beginning of a linked list with the k-th node from the end of the list.
 */
std::pair<int, ListNode *> swapNodes(ListNode *current, int k, int i) {
    if (current == nullptr)
        return std::make_pair(i - 1, static_cast<ListNode *>(nullptr));
    
    std::pair<int, ListNode *> result = swapNodes(current->next, k, i + 1);
    int kFromEnd = result.first - k;
    k--;

    if (i == std::max(k, kFromEnd))
        result.second = current;
    else if (i == std::min(k, kFromEnd))
        swapNexts(current, result.second);

    return result;
}

/**
 * Swap the k-th node from the beginning of a linked list with the k-th node from the end of the list.
 */
ListNode* swapNodes(ListNode* head, int k) {
    ListNode tempHead(0, head);
    swapNodes(&tempHead, k, 0);

    return tempHead.next;
}

int main() {
    ListNode last(5, nullptr);
    ListNode a(9, &last);
    ListNode b(0, &a);
    ListNode c(3, &b);
    ListNode d(8, &c);
    ListNode e(7, &d);
    ListNode fourth(6, &e);
    ListNode third(6, &fourth);
    ListNode second(90, nullptr);
    ListNode head(100, &second);
    swapNodes(&head, 2);
}