class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxSum = nums[0];
        long long currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currentSum = max((long long)nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};