class Solution {
public:
    int solve(TreeNode* curr, bool isLeft) {
        if (curr == NULL) {
            return 0;
        }
        if (curr->left == NULL && curr->right == NULL && isLeft == true) {
            return curr->val;
        }
        return solve(curr->left, true) + solve(curr->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) { 
        return solve(root, false); 
    }
};