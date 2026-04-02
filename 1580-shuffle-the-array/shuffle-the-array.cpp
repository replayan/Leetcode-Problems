class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int base = 1001; 

        // Step 1: Encode both values into first n positions
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] + (nums[i + n] % base) * base;
        }

        // Step 2: Decode and rearrange from back
        for (int i = n - 1; i >= 0; i--) {
            int y = nums[i] / base;
            int x = nums[i] % base;

            nums[2 * i + 1] = y;
            nums[2 * i] = x;
        }

        return nums;
    }
};