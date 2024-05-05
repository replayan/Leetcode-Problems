/*
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};
*/

// a slight better way to delete

class Solution {
public:
    void deleteNode(ListNode* node) {
        // save a pointer to the next node
        ListNode* nextNode = node->next;
        
        // copy the data of the next node into the current node
        *node = *nextNode;
        
        // deallocate the memory of the next node
        delete nextNode;
    }
};

