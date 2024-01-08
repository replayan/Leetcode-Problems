class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        int r = root->val>=low && root->val <= high ? root->val : 0;
        if (root->val > low) {
            r += rangeSumBST(root->left, low, high);
        }
        if (root->val < high) {
            r += rangeSumBST(root->right, low, high);
        }
        return r;
    }
};