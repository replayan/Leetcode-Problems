class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n <= 0) {
            return head; // Handle empty list or invalid n
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast n nodes ahead
        for (int i = 0; i < n; i++) {
            if (fast == nullptr) {
                // n is equal to the length of the list, remove the last node
                return head->next;
            }
            fast = fast->next;
        }

        // Handle the case where n is equal to the length of the list
        if (fast == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Iterate together until fast reaches the end
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the node
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};
