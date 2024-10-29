class Solution {
    int cal(vector<vector<int>>& dp, const vector<vector<int>>& g, int x,
            int y) {
        if (x < 0 || x >= dp.size() || y < 0 || y >= dp[0].size()) {
            return -1;
        }
        if (dp[x][y] >= 0) {
            return dp[x][y];
        }
        dp[x][y] = 0;
        if (y + 1 >= dp[0].size()) {
            return 0;
        }

        if (g[x][y + 1] > g[x][y]) {
            dp[x][y] = max(dp[x][y], cal(dp, g, x, y + 1) + 1);
        }
        if (x && g[x - 1][y + 1] > g[x][y]) {
            dp[x][y] = max(dp[x][y], cal(dp, g, x - 1, y + 1) + 1);
        }
        if (x + 1 < dp.size() && g[x + 1][y + 1] > g[x][y]) {
            dp[x][y] = max(dp[x][y], cal(dp, g, x + 1, y + 1) + 1);
        }
        return dp[x][y];
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int r = 0;
        for (int i = 0; i < m; ++i) {
            r = max(r, cal(dp, grid, i, 0));
        }
        return r;
    }
};