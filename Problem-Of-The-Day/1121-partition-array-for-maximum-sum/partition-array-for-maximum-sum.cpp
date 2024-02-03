class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        const int n = A.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1, m = 0; j >= 0 && i - j <= K; --j) {
                m = max(m, A[j]);
                dp[i] = max(dp[i], m * (i - j) + dp[j]);
            }
        }
        return dp[n];
    }
};