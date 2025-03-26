class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        const int m = grid[0][0] % x;
        vector<int> v;
        int s = 0;
        for (const auto& g : grid) {
            for (int y : g) {
                if (y % x != m) {
                    return -1;
                }
                v.push_back(y / x);
                s += v.back();
            }
        }
        sort(v.begin(), v.end());
        int r = s;
        const int n = v.size();
        for (int i = v[0], t = 0, sum = 0, j = 0; i <= v.back(); ++i) {
            for (; j < n && v[j] <= i; ++t, sum += v[j++])
            ;
            r = min(r, t * i - sum + s - sum - (n - t) * i);
        }
        return r;
    }
};