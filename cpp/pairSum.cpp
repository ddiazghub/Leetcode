#include <limits>
#include <iostream>
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
 * Reverse a linked list and return the head.
 */
inline ListNode* reverse(ListNode* head) {
    ListNode *reversed = nullptr;

    while (head != nullptr) {
        ListNode *temp = head->next;
        head->next = reversed;
        reversed = head;
        head = temp;
    }

    return reversed;
}

/**
 * In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
 * The twin sum is defined as the sum of a node and its twin.
 * Given the head of a linked list with even length, return the maximum twin sum of the linked list.
 */
int pairSum(ListNode* head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *current = head;
    ListNode *twin = reverse(slow);
    int max = std::numeric_limits<int>::min();

    while (twin != nullptr) {
        max = std::max(max, current->val + twin->val);
        current = current->next;
        twin = twin->next;
    }

    return max;
}

int main() {
    
}