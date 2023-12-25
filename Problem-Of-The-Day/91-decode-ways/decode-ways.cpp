class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
        vector<int> dp(3);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i % 3] = 0;
            if (dp[(i - 1) % 3] && s[i - 1] != '0') {
                dp[i % 3] += dp[(i - 1) % 3];
            }
            if (i >= 2 && dp[(i - 2) % 3] && s[i - 2] >= '1' &&
                s[i - 2] <= '2' &&
                (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26) {
                dp[i % 3] += dp[(i - 2) % 3];
            }
        }
        return dp[n % 3];
    }
};