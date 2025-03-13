class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size(), m = queries.size();
        int left = 0, right = m;
        while (left <= right) {
            const int mid = (left + right) >> 1;
            vector<int> d(n + 1);
            for (int i = 0; i < mid; ++i) {
                d[queries[i][0]] += queries[i][2];
                d[queries[i][1] + 1] -= queries[i][2];
            }
            bool ok = true;
            for (int i = 0, v = 0; ok && i < n; ok = (v += d[i]) >= nums[i], ++i)
            ;
            if (ok) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ++right <= m ? right : -1;
        
    }
};