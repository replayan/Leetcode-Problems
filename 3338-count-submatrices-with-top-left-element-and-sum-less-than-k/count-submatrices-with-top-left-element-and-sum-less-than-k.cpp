class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        int r = 0;
        for (int i = 1; i <= m; ++i) {
            assert(grid[i - 1].size() == n);
            for (int j = 1, sum = 0; j <= n; ++j) {
                assert(grid[i - 1][j - 1] >= 0 && grid[i - 1][j - 1] <= 1000);
                sum += grid[i - 1][j - 1];
                s[i][j] = s[i - 1][j] + sum;
                r += s[i][j] <= k;
            }
        }
        return r;
    }
};