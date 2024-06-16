class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int patches = 0;
        int i = 0;
        
        while (miss <= n) {
            // If the current number in the array is within the current miss range
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                // Otherwise, add a patch
                miss *= 2;
                patches++;
            }
        }
        
        return patches;
    }
};
