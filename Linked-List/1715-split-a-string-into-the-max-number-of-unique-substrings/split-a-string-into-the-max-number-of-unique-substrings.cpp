class Solution {
    int dfs(const string& s, unordered_set<string>& all, int ind) {
        if (ind >= s.length()) {
            return 0;
        }
        int r = -10000;
        for (int i = ind; i < s.length(); ++i) {
            const string temp = s.substr(ind, i - ind + 1);
            if (!all.count(temp)) {
                all.insert(temp);
                r = max(r, dfs(s, all, i + 1));
                all.erase(temp);
            }
        }
        return r + 1;
    }

public:
    int maxUniqueSplit(string s) {
        unordered_set<string> all;
        return dfs(s, all, 0);
    }
};