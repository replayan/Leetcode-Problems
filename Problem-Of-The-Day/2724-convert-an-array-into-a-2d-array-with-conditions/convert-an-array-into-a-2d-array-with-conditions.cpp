class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = 0;
        vector<int> v(nums.size());
        for (int x : nums) {
            n = max(n, ++v[x - 1]);
        }
        vector<vector<int>> r(n);
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[i]; ++j) {
                r[j].push_back(i + 1);
            }
        }
        return r;
    }
};