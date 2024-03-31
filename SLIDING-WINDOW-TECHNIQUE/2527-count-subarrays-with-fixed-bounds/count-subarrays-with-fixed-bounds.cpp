// Updated variable names for better understanding...

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int lastMinIndex = -1;
        int lastMaxIndex = -1;
        int resetIndex = -1;
        for (int left = 0; left < nums.size(); ++left) {
            if (nums[left] < minK || nums[left] > maxK) {
                lastMinIndex = lastMaxIndex = -1;
                resetIndex = left;
            }
            if (nums[left] == minK) {
                lastMinIndex = left;
            }
            if (nums[left] == maxK) {
                lastMaxIndex = left;
            }
            count += max(0, min(lastMinIndex, lastMaxIndex) - resetIndex);
        }
        return count;
    }
};