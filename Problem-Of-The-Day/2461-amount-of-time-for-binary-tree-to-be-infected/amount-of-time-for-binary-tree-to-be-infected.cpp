/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<int, bool> dfs(TreeNode* root, int dep, int start, int&start_dep, int &ans) {
        if (root == nullptr) {
            return {-1, false};
        }
        const auto p1 = dfs(root->left, dep + 1, start, start_dep, ans);
        const auto p2 = dfs(root->right, dep + 1, start, start_dep, ans);
        const int r = max(p1.first, p2.first) + 1;
        if (root->val == start) {
            start_dep = dep;
            ans = max(ans, r);
            return {r, true};
        }
        if (p1.second) {
            ans = max(ans, p2.first + 1 + start_dep - dep);
        }
        if (p2.second) {
            ans = max(ans, p1.first + 1 + start_dep - dep);
        }
        return {r, p1.second || p2.second};
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        int start_dep = 0, ans = 0;
        dfs(root, 0, start, start_dep, ans);
        return ans;
        
    }
};