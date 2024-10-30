class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const int n = nums.size();
        vector<int> v, dp(n);
        for (int i = 0; i < n; ++i) {
            auto t = lower_bound(v.begin(), v.end(), nums[i]);
            dp[i] = distance(v.begin(), t) + 1;
            if (t == v.end()) {
                v.push_back(nums[i]);
            } else {
                *t = nums[i];
            }
        }
        v.clear();
        int r = 0;
        for (int i = n - 1; i >= 0; --i) {
            auto t = lower_bound(v.begin(), v.end(), nums[i]);
            const int d = distance(v.begin(), t) + 1;
            if (d >= 2 && dp[i] >= 2) {
                r = max(r, d + dp[i] - 1);
            }
            if (t == v.end()) {
                v.push_back(nums[i]);
            } else {
                *t = nums[i];
            }
        }
        return n - r;
    }
};