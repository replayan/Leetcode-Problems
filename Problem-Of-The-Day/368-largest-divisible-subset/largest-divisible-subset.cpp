class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1); 
        vector<int> prev(n, -1); 
        vector<int> res;
        int maxIdx = 0; 
        int maxSize = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIdx = i;
            }
        }
        while (maxIdx != -1) {
            res.push_back(nums[maxIdx]);
            maxIdx = prev[maxIdx];
        }
        return res;
    }
};
