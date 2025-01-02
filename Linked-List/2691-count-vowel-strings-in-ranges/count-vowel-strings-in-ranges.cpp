class Solution {
    bool ok(char c) {
        return strchr("aeiou", c);
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const int n = words.size();
        vector<int> p(n + 1);
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] + (ok(words[i][0]) && ok(words[i].back()));
        }
        vector<int> r;
        for (const auto& q : queries) {
            r.push_back(p[q[1] + 1] - p[q[0]]);
        }
        return r;
        
    }
};