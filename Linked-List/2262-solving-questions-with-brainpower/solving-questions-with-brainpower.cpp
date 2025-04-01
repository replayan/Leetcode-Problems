class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int n = questions.size();
        vector<long long> dp(n);
        dp[n - 1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = max(dp[i + 1], questions[i][0] + (i + questions[i][1] + 1 < n ? dp[i + questions[i][1] + 1] : 0));
        }
        return dp[0];
    }
};