class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(2);
        dp[1] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp = {max(dp[0], dp[1]), dp[0] + nums[i]};
        }
        return max(dp[0], dp[1]);
    }
};