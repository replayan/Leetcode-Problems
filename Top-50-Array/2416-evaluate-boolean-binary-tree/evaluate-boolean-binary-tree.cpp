class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (!root->right && !root->left) {
            return root->val;
        }
        int a = evaluateTree(root->left);
        int b = evaluateTree(root->right);
        if (root->val == 2) {
            return a | b;
        }
        return a & b;
    }
};