class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int total_sum = 0;
        dfs(root, 0, total_sum);
        return total_sum;
    }
    void dfs(TreeNode* node, int num, int& total_sum) {
        if (!node) {
            return;
        }
        num = num * 10 + node->val;
        if (!node->left && !node->right) {
            total_sum += num;
            return;
        }
        dfs(node->left, num, total_sum);
        dfs(node->right, num, total_sum);
    }
};