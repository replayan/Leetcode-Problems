class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;

        // Tracks the last index of an element equal to minK encountered so far
        int lastMinIndex = -1;

        // Tracks the last index of an element equal to maxK encountered so far
        int lastMaxIndex = -1;

        // This variable will be used to mark the beginning of a new subarray
        // after encountering an element outside the range [minK, maxK]
        int startAgain = -1;

        for (int left = 0; left < nums.size(); ++left) {

            // If the current element is outside the desired range
            if (nums[left] < minK || nums[left] > maxK) {
                // Reset the starting point for the next subarray
                startAgain = left;
            } else {
                // Update lastMinIndex if the current element is equal to minK
                if (nums[left] == minK) {
                    lastMinIndex = left;
                }

                // Update lastMaxIndex if the current element is equal to maxK
                if (nums[left] == maxK) {
                    lastMaxIndex = left;
                }

                // Calculate the valid length of the current subarray
                // considering both minK and maxK elements We use max(0, ...) to
                // ensure we don't get a negative count (which wouldn't make
                // sense) min(lastMinIndex, lastMaxIndex) - startAgain
                // represents the number of valid elements in the subarray
                count += max(0, min(lastMinIndex, lastMaxIndex) - startAgain);
            }
        }
        return count;
    }
};
