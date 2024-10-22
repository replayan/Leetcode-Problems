class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        multiset<long long> s;
        s.insert(root->val);
        queue<TreeNode*> q;
        for (q.push(root); !q.empty();) {
            long long sum = 0;
            for (int i = q.size(); i; --i) {
                auto* temp = q.front();
                q.pop();
                if (temp->left) {
                    q.push(temp->left);
                    sum += temp->left->val;
                }
                if (temp->right) {
                    q.push(temp->right);
                    sum += temp->right->val;
                }
            }
            if (sum) {
                s.insert(sum);
            }
            if (s.size() > k) {
                s.erase(s.begin());
            }
        }
        return s.size() == k ? *s.begin() : -1;
    }
};