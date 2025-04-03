class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int n = nums.size();
        vector<int> leftmin(n), leftmax(n), rightmin(n), rightmax(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                leftmin[i] = leftmax[i] = nums[i];
            } else {
                leftmin[i] = min(nums[i], leftmin[i - 1]);
                leftmax[i] = max(nums[i], leftmax[i - 1]);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                rightmin[i] = rightmax[i] = nums[i];
            } else {
                rightmin[i] = min(nums[i], rightmin[i + 1]);
                rightmax[i] = max(nums[i], rightmax[i + 1]);
            }
        }
        long long r = 0;
        for (int i = 1; i + 1 < n; ++i) {
            r = max(r, static_cast<long long>(leftmin[i - 1] - nums[i]) *
                           rightmin[i + 1]);
            r = max(r, static_cast<long long>(leftmin[i - 1] - nums[i]) *
                           rightmax[i + 1]);
            r = max(r, static_cast<long long>(leftmax[i - 1] - nums[i]) *
                           rightmin[i + 1]);
            r = max(r, static_cast<long long>(leftmax[i - 1] - nums[i]) *
                           rightmax[i + 1]);
        }
        return r;
    }
};