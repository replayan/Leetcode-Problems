class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long r = 0;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    r = max(r, (nums[i] - nums[j]) * 1LL * nums[k]);
                }
            }
        }
        return r;
    }
};