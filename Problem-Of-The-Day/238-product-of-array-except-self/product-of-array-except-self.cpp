class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /* TLE brute force
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 0; i < n; ++i) {
            int pro = 1;
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                pro *= nums[j];
            }
            ans[i] = pro;
        }
        return ans;
        */
        int n = nums.size();
        vector<int> res(nums.size(), 1);
        int left = 1;
        for (int i = 0; i < n; ++i) {
            res[i] *= left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};