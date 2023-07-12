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
 * Convert a binary number represented as a linked list to a decimal number.
 */
int getDecimalValue(ListNode *head) {
    int decimal = 0;

    for (ListNode *current = head; current != nullptr; current = current->next)
        decimal = (decimal << 1) + current->val;

    return decimal;
}