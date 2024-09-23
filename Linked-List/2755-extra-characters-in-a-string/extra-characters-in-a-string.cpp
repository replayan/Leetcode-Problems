class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        const int n = s.length();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            for (int len = 1; len <= i; ++ len) {
               for (const auto& word : dict) {
                   if (word == s.substr(i - len, len)) {
                       dp[i] = max(dp[i], dp[i - len] + len);
                   }
               }
            }
        }
        return n - dp[n];
        
    }
};