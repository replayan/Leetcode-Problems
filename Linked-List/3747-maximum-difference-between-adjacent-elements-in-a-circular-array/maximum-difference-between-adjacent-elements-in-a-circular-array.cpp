class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int r = abs(nums[0] - nums.back());
        for (int i = 1; i < nums.size(); ++i) {
            r = max(r, abs(nums[i] - nums[i - 1]));
        }
        return r;
    }
};