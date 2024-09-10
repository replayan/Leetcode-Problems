class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        for (ListNode* temp = head; temp->next != nullptr;) {
            ListNode* next = temp->next;
            temp->next = new ListNode(gcd(temp->val, next->val), next);
            temp = next;
        }
        return head;
    }
};