class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        long long leftSum = 0;
        int validSplits = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;
            if (leftSum >= rightSum) {
                validSplits++;
            }
        }
        return validSplits;
    }
};
