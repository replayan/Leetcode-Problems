class Solution {
 bool dfs(ListNode* temp) {
        if (temp == nullptr) {
            return false;
        }
        temp->val += temp->val + dfs(temp->next);
        if (temp->val >= 10) {
            temp->val -= 10;
            return true;
        }
        return false;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        return dfs(head) ? new ListNode(1, head) : head;
    }
};