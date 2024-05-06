class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // If the linked list is empty or has only one node, return the head
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Recursively remove nodes from the rest of the list
        ListNode* nextNode = removeNodes(head->next);

        // If the current node's value is less than the next node's value
        if (head->val < nextNode->val) {
            // Delete the current node
            delete head;
            // Return the next node as the new head
            return nextNode;
        }

        // Otherwise, keep the current node
        // and update its next pointer to the modified list
        head->next = nextNode;
        return head;
    }
};