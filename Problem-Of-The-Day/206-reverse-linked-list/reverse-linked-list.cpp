class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = NULL;
        ListNode* current = head;
        while (current != NULL) {
            ListNode* nextTemp = current->next;
            current->next = previous;
            previous = current;
            current = nextTemp;
        }
        return previous;
    }
};