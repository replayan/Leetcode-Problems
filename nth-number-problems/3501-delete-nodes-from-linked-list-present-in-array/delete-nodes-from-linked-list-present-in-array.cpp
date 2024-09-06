class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Step 1: Store all nums in a set for O(1) lookup
        unordered_set<int> toRemove(nums.begin(), nums.end());

        // Create a dummy node to handle edge cases such as removing the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;   // Previous node starts as the dummy
        ListNode* current = head; // Current node starts at the head

        // Step 2: Traverse the list
        while (current != nullptr) {
            if (toRemove.count(current->val)) { // Node value exists in nums
                prev->next =
                    current->next; // Remove current node by skipping it
            } else {
                prev = current; // Move prev pointer forward if no removal
            }
            current = current->next; // Move to the next node
        }

        // Step 3: Return the modified list (dummy->next is the new head)
        return dummy->next;
    }
};
