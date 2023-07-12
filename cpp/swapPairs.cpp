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
 * Swaps the pair of nodes after the current node in a linked list.
 * Returns true if the pair was swapped and false if any of the 2 next nodes is null.
 */
bool swapNextPair(ListNode *node) {
    if (node->next != nullptr && node->next->next != nullptr) {
        ListNode *temp = node->next->next;
        node->next->next = temp->next;
        temp->next = node->next;
        node->next = temp;

        return true;
    }

    return false;
}

/**
 * Swap every pair of nodes in a linked list.
 */
ListNode *swapPairs(ListNode *head) {
    ListNode tempHead(0, head);
    ListNode *current = &tempHead;

    while (swapNextPair(current)) {
        current = current->next;
        current = current == nullptr ? current : current->next;
    }

    return tempHead.next;
}

int main() {
    
}