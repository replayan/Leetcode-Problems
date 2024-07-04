class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

        /*
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        // Skip the first `0`
        head = head->next;
        
        while (head != nullptr) {
            // Sum all values between two consecutive `0`s
            int current_sum = 0;
            while (head != nullptr && head->val != 0) {
                current_sum += head->val;
                head = head->next;
            }
            
            // Create a new node with the sum and attach it to the result list
            if (current_sum != 0) {
                current->next = new ListNode(current_sum);
                current = current->next;
            }
            
            // Skip the current `0` and move to the next node
            if (head != nullptr) {
                head = head->next;
            }
        }
        
        return dummy->next;
        */

        ListNode* curr = head;
        while (curr->next) {
            ListNode* node = curr->next;
            curr = curr->next;
            while (curr->next->val != 0) {
                node->val += curr->next->val;
                curr = curr->next;
            }
            curr = curr->next;
            node->next = curr->next;
        }
        return head->next;
    }
};