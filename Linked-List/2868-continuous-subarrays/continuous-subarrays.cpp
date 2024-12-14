class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        const int n = nums.size();
        map<int, int> have;
        long long r = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            for (; j < n; ++j) {
                ++have[nums[j]];
                if (have.rbegin()->first - have.begin()->first > 2) {
                    if (--have[nums[j]] == 0) {
                        have.erase(nums[j]);
                        break;
                    }
                }
            }
            r += j - i;
            if (--have[nums[i]] == 0) {
                have.erase(nums[i]);
            }
        }
        return r;
    }
};