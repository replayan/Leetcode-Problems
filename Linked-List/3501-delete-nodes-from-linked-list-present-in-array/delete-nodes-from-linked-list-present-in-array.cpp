class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toRemove(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;   
        ListNode* current = head; 

        while (current != nullptr) {
            if (toRemove.count(current->val)) { // Node value exists in nums
                prev->next = current->next; // Removing current node by skipping it
            } else {
                prev = current; // Move prev pointer forward if no removal
            }
            current = current->next; // Move to the next node
        }

        return dummy->next;
    }
};
