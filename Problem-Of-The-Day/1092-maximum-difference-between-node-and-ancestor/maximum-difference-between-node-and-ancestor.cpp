class Solution {
    int dfs(TreeNode* root, int maxi, int mini) {
        if (root == nullptr) {
            return 0;
        }
        const int r = max(abs(root->val - mini), abs(root->val - maxi));
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        return max(max(dfs(root->left, maxi, mini), dfs(root->right, maxi, mini)), r);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};