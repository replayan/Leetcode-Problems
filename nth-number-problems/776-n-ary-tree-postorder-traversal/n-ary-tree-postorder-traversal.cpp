class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> r;
        stack<const Node*> s;
        for (s.push(root); !s.empty();) {
            const auto *p = s.top();
            s.pop();
            if (p) {
                r.push_back(p->val);
                for (const auto *c : p->children) {
                    s.push(c);
                }
            }
        }
        reverse(r.begin(), r.end());
        return r;
    }
};