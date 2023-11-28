class Solution {
    const int M = 1000000007;
    void add(int &x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
    }
public:
    int numberOfWays(string corridor) {
        const int n = corridor.size();
        vector<int> dp(n + 1);
        for (int i = dp[0] = 1, j = 0, s = 0, num = 0; i <= n; ++i) {
            if (corridor[i - 1] == 'S') {
                if (++num >= 2) {
                    for (s = dp[j]; corridor[j++] != 'S'; add(s, dp[j]))
                    ;
                }
            }
            dp[i] = s;
        }
        return dp[n];
        
    }
};