#include <vector>

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
 * Find if a linked list is a palindrome.
 */
bool isPalindrome(ListNode* head) {
    ListNode *fast = head;
    ListNode *slow = head;
    std::vector<int> stack;

    while (fast != nullptr && fast->next != nullptr) {
        stack.push_back(slow->val);
        fast = fast->next->next;
        slow = slow->next;
    }

    if (slow == head)
        return true;
    
    if (fast != nullptr)
        slow = slow->next;
        
    while (slow != nullptr) {
        if (slow->val != stack.back())
            return false;

        stack.pop_back();
        slow = slow->next;
    }

    return true;
}

int main() {

}