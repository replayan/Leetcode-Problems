class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        int r = 0;
        vector<unordered_map<long long, int>> dp(n);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                const long long d = static_cast<long long>(nums[i]) - nums[j];
                ++dp[i][d];
                if (dp[j].count(d)) {
                    r += dp[j][d];
                    dp[i][d] += dp[j][d];
                }
            }
        }
        return r;
    }
};