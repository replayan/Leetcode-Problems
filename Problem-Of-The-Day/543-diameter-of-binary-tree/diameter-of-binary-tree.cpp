class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode* root, int& res) {
        if (!root)
            return -1;

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);

        res = max(res, 2 + left + right);

        return 1 + max(left, right);
    }
};