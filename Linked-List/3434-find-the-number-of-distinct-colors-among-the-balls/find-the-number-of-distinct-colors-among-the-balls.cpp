class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> c, s;
        vector<int> r;
        for (const auto& q : queries) {
            if (c.count(q[0]) && --s[c[q[0]]] == 0) {
                s.erase(c[q[0]]);
            }
            ++s[q[1]];
            c[q[0]] = q[1];
            r.push_back(s.size());
        }
        return r;
    }
};
