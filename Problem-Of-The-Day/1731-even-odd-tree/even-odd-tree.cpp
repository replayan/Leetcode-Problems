class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool evenLvl = true;
        while (!q.empty()) {
            int n = q.size(), prev;
            if (evenLvl) {
                prev = INT_MIN;
            } else {
                prev = INT_MAX;
            }
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();
                if (evenLvl && (curr->val % 2 == 0 || curr->val <= prev)) {
                    return false;
                }
                if (!evenLvl && (curr->val % 2 != 0 || curr->val >= prev)) {
                    return false;
                }
                prev = curr->val;
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            evenLvl = !evenLvl;
        }
        return true;
    }
};