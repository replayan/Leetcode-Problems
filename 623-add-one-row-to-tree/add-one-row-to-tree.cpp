class Solution {
    void dfs(TreeNode* root, int v, int now, int d) {
        if (root != nullptr) {
            if (now == d) {
                root->left = new TreeNode(v, root->left, nullptr);
                root->right = new TreeNode(v, nullptr, root->right);
            } else {
                dfs(root->left, v, now + 1, d);
                dfs(root->right, v, now + 1, d);
            }
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            return new TreeNode(v, root, nullptr);
        }
        dfs(root, v, 1, d - 1);
        return root;
    }
};