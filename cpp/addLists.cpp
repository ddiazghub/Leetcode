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
 * Add two numbers represented by singly linked lists.
 * Despite manual memory management being a bad practice, this exercise forces you to do it.
 */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *fakeHead = new ListNode(0, new ListNode);
    ListNode *tail = fakeHead;

    while (l1 != nullptr || l2 != nullptr) {
        tail = tail->next;

        if (l1 != nullptr) {
            tail->val += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            tail->val += l2->val;
            l2 = l2->next;
        }
        
        tail->next = new ListNode(tail->val / 10);
        tail->val %= 10;
    }

    if (tail->next->val == 0) {
        delete tail->next;
        tail->next = nullptr;
    }

    ListNode *head = fakeHead->next;
    delete fakeHead;

    return head;
}

int main() {

}