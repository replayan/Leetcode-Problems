class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = 1 + ((j == i) ? 0 : dp[i + 1][j]);
                for (int k = i + 1; k <= j; ++k) {
                    if (s[i] == s[k]) {
                        dp[i][j] = min(dp[i][j],
                                       ((k - 1 >= i) ? dp[i][k - 1] : 0) +
                                           ((k + 1 <= j) ? dp[k + 1][j] : 0));
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};