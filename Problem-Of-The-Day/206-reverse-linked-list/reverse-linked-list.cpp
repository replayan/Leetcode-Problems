class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = NULL;
        while (head != NULL) {
            ListNode* nextTemp = head->next;
            head->next = previous;
            previous = head;
            head = nextTemp;
        }
        return previous;
    }
};