class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        int n = size(nums);
        for (int i = 0; i < n; ++i) {
            bool ifDuplicate = false;
            for (int j = -0; j < n; ++j) {
                if (i != j && nums[i] == nums[j]) {
                    ifDuplicate = true;
                    break;
                }
            }
            if (!ifDuplicate) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};