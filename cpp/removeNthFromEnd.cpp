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
 * Remove Nth node from the end of a linked list.
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0, head);
    ListNode *end = &dummy;

    for (int i = 0; i <= n && end != nullptr; i++)
        end = end->next;

    ListNode *current = &dummy;

    while (end != nullptr) {
        current = current->next;
        end = end->next;
    }

    current->next = current->next->next;

    return dummy.next;
}

int main() {

}