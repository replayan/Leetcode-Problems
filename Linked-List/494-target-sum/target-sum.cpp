class Solution {
    void countWays(const vector<int>& nums, int index, int currentSum,
                   int target, int& count) {
        if (index == nums.size()) {
            if (currentSum == target) {
                ++count;
            }
            return;
        }

        // Include the current number as positive
        countWays(nums, index + 1, currentSum + nums[index], target, count);

        // Include the current number as negative
        countWays(nums, index + 1, currentSum - nums[index], target, count);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        countWays(nums, 0, 0, target, count);
        return count;
    }
};
