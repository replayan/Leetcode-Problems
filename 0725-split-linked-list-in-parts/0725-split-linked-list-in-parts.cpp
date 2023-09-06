class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }
        
        int part_size = length / k;
        int extra = length % k;
        vector<ListNode*> result;
        current = head;
        
        for (int i = 0; i < k; i++) {
            int current_part_size = part_size + (i < extra ? 1 : 0);
            
            if (!current_part_size) {
                result.push_back(nullptr);
            } else {
                ListNode* part_head = current;
                while (--current_part_size > 0) {
                    current = current->next;
                }
                ListNode* next_part_head = current->next;
                current->next = nullptr;
                result.push_back(part_head);
                current = next_part_head;
            }
        }
        
        return result;
    }
};
