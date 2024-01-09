/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getLeaves(const TreeNode* r, vector<int>& all) {
        if (r == nullptr) {
            return;
        }
        if (r->left == nullptr && r->right == nullptr) {
            all.push_back(r->val);
            return;
        }
        getLeaves(r->left, all);
        getLeaves(r->right, all);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        getLeaves(root1, a);
        getLeaves(root2, b);
        return a == b;
    }
};