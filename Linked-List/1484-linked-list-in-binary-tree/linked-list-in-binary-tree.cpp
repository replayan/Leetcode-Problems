class Solution {
    bool match(ListNode* head, TreeNode* root) {
        return head == nullptr || (root != nullptr && head->val == root->val &&
                                   (match(head->next, root->left) ||
                                    match(head->next, root->right)));
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return match(head, root) ||
               (root != nullptr &&
                (isSubPath(head, root->left) || isSubPath(head, root->right)));
    }
};