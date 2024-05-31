class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNumber = 0;
        for (int i = 0; i < size(nums); ++i) {
            singleNumber ^= nums[i];
        }
        return singleNumber;
    }
};