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
 * Remove all elements from a linked list matching val.
 */
ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy(0, head);
    ListNode *current = &dummy;

    while (current != nullptr && current->next != nullptr) {
        if (current->next->val == val) {
            ListNode *temp = current->next->next;
            delete current->next;
            current->next = temp;
        } else {
            current = current->next;
        }
    }

    return dummy.next;
}