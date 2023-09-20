// REV REQUIRED REV.21.09.23

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; ++i) {
            totalSum += nums[i];
        }
        int target = totalSum - x;
        if (target < 0) return -1;
        if (target == 0) return n;
        int left = 0, minOps = INT_MAX, currentSum = 0;
        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];
            while (currentSum > target) {
                currentSum -= nums[left];
                ++left;
            }
            if (currentSum == target) {
                minOps = min(minOps, n - (right - left + 1));
            }
        }
        return minOps == INT_MAX ? -1 : minOps;
    }
};
