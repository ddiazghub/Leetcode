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
 * Given the head of a singly linked list, return the middle node of the linked list.
 */
ListNode *middleNode(ListNode *head) {
    ListNode *fast = head->next;
    ListNode *slow = head;

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;

        if (fast != nullptr)
            fast = fast->next;
    }

    return slow;
}

int main() {

}