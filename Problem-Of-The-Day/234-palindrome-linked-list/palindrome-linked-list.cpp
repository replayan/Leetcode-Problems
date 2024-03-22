class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> temp;
        ListNode* current = head;
        while (current != NULL) {
            temp.push_back(current->val);
            current = current->next;
        }
        for (int i = 0, j = temp.size() - 1; i < j; i++, --j) {
            if (temp[i] != temp[j]) {
                return false;
            }
        }
        return true;
    }
};