class Solution {
    bool ok(const string &a, const string &b) {
        if (a.length() != b.length()) {
            return false;
        }
        int d = 0;
        for (int i = 0; d < 2 && i < a.length(); ++i) {
            d += a[i] != b[i];
        }
        return d == 1;
    }
    
    void dfs(int ind, const vector<int> &pre, const vector<string > &words, vector<string> &r) {
        if (ind >= 0) {
            dfs(pre[ind], pre, words, r);
            r.push_back(words[ind]);
        }
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n = words.size();
        vector<int> dp(n, 1), pre(n, -1);
        int ind = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && ok(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    if (dp[ind] < dp[i]) {
                        ind = i;
                    }
                    pre[i] = j;
                }
            }
        }
        vector<string> r;
        dfs(ind, pre, words, r);
        return r;
    }
};