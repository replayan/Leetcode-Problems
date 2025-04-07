class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();

        // -1: unvisited, 0: false, 1: true
        vector<vector<int>> memo(n, vector<int>(target + 1, -1));

        return dfs(nums, 0, 0, target, memo);
    }

    bool dfs(vector<int>& nums, int index, int currSum, int target, vector<vector<int>>& memo) {
        if (currSum == target) return true;
        if (index >= nums.size() || currSum > target) return false;

        if (memo[index][currSum] != -1) return memo[index][currSum];

        bool include = dfs(nums, index + 1, currSum + nums[index], target, memo);
        bool exclude = dfs(nums, index + 1, currSum, target, memo);

        memo[index][currSum] = include || exclude;
        return memo[index][currSum];
    }
};
