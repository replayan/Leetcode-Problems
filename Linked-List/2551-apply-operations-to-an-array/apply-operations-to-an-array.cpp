class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i + 1] == nums[i]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                nums[j++] = nums[i];
            }
        }
        for (; j < n; ++j) {
            nums[j] = 0;
        }
        return nums;
    }
};