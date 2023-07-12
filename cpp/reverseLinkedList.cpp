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
 * Reverse a linked list and return the head.
 */
ListNode* reverseList(ListNode* head) {
    ListNode *reversed = nullptr;

    while (head != nullptr) {
        ListNode *temp = head->next;
        head->next = reversed;
        reversed = head;
        head = temp;
    }

    return reversed;
}

int main() {
    
}