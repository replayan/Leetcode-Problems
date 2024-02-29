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
    bool isOdd(int x) {
        return x & 1;
    }
    bool dfs(TreeNode* root, int dep, vector<int>& last) {
        if (root == nullptr) {
            return true;
        }
        if (isOdd(dep)) {
            if (isOdd(root->val) || (last[dep] > 0 && last[dep] <= root->val)) {
                return false;
            }
        } else if (!isOdd(root->val) || last[dep] >= root->val) {
            return false;
        }
        last[dep] = root->val;
        return dfs(root->left, dep + 1, last) && dfs(root->right, dep + 1, last);
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<int> last(100005);
        return dfs(root, 0, last);
        
    }
};