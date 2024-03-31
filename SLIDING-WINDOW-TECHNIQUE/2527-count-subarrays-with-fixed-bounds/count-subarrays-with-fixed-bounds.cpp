class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int prev_minimum = -1;
        int prev_maximum = -1;
        int startAgain = -1;
        for (int left = 0; left < nums.size(); ++left) {
            if (nums[left] < minK || nums[left] > maxK) {
                prev_minimum = prev_maximum = -1;
                startAgain = left;
            }
            if (nums[left] == minK) {
                prev_minimum = left;
            }
            if (nums[left] == maxK) {
                prev_maximum = left;
            }
            count += max(0, min(prev_minimum, prev_maximum) - startAgain);
        }
        return count;
    }
};