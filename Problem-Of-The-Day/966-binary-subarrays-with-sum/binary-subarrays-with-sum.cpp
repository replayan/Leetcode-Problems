class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        preSum[0] = nums[0];
        for (int i = 0; i < n; ++i) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        int count = 0;
        unordered_map<int, int> mp;
        for (int sum : preSum) {
            count += mp[sum - goal];
            mp[sum]++;
        }
        return count;
    }
};