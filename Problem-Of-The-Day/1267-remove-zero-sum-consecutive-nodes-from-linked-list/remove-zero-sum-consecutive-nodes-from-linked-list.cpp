class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int psum = 0;
        unordered_map<int, ListNode*> mp;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;
        while (head != NULL) {
            psum += head->val;
            if (mp.find(psum) != mp.end()) {
                ListNode* start = mp[psum];
                ListNode* temp = start;
                int presum = psum;
                while (temp != head) {
                    temp = temp->next;
                    presum += temp->val;
                    if (temp != head) {
                        mp.erase(presum);
                    }
                }
                start->next = head->next;
            } else {
                mp[psum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};