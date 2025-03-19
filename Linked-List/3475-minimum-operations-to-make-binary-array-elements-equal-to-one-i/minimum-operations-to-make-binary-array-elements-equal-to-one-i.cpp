class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        assert(n >= 3 && n <= 100000);
        for (int x : nums) {
            assert(x == 0 || x == 1);
        }
        int r = 0;
        for (int i = 0; i + 2 < n; ++i) {
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++r;
            }
        }
        return nums[n - 2] && nums[n - 1] ? r : -1;
    }
};