class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> temp;
        ListNode* current = head;
        while (current != NULL) {
            temp.push_back(current->val);
            current = current->next;
        }
        int i = 0, j = temp.size() - 1;
        while (i < j) {
            if (temp[i] != temp[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};