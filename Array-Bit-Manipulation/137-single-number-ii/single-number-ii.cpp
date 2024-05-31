class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i < size(nums); ++i) {
            int count = 0;
            for (int j = 0; j < size(nums); ++j) {
                if (nums[i] == nums[j]) {
                    count += 1;
                }
            }
            if (count == 1) {
                return nums[i];
            }
        }
        return -1;
    }
};