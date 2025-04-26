class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int lastMinIndex = -1;
        int lastMaxIndex = -1;
        int startAgain = -1;

        for (int left = 0; left < nums.size(); ++left) {
            if (nums[left] < minK || nums[left] > maxK) {
                startAgain = left;
            } else {
                if (nums[left] == minK) {
                    lastMinIndex = left;
                }
                if (nums[left] == maxK) {
                    lastMaxIndex = left;
                }
                count += max(0, min(lastMinIndex, lastMaxIndex) - startAgain);
            }
        }
        return count;
    }
};
