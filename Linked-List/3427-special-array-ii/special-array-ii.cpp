class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            if ((nums[i] ^ nums[i + 1]) & 1) {
                dp[i] = dp[i + 1] + 1;
            }
        }
        vector<bool> r;
        for (const auto& q : queries) {
            r.push_back(q[1] - q[0] < dp[q[0]]);
        }
        return r;
    }
};