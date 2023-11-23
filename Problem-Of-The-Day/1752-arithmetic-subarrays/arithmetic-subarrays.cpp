class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        const int m = l.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; ++i) {
            ans[i] = true;
            if (r[i] > l[i] + 1) {
                vector<int> v(r[i] - l[i] + 1);
                for (int j = l[i]; j <= r[i]; ++j) {
                    v[j - l[i]] = nums[j];
                }
                sort(v.begin(), v.end());
                for (int j = 2, d = v[1] - v[0]; ans[i] && j < v.size(); ++j) {
                    ans[i] = (v[j] - v[j - 1] == d);
                }
            }
        }
        return ans;
        
    }
};