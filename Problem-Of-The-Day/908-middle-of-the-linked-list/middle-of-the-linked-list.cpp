class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head || !head->next) {
            return head; // Return the head if the list is empty or has only one node
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Move the fast pointer twice as fast as the slow pointer
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the number of nodes is odd, the slow pointer will be at the middle node
        // If the number of nodes is even, the slow pointer will be at the node before the middle node
        // In the latter case, we move the slow pointer one step forward to reach the middle node
        if (fast->next) {
            slow = slow->next;
        }

        return slow;
    }
};