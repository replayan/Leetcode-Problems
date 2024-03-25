class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size();) {
            int correct_index = nums[i] - 1;
            if (nums[i] != nums[correct_index]) {
                swap(nums[i], nums[correct_index]);
            } else {
                ++i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};