class Solution {
    bool dfs(int x, int y, vector<vector<int>>& a, vector<vector<int>>& b) {
        if (x < 0 || x >= a.size() || y < 0 || y >= a[x].size() ||
            b[x][y] != 1) {
            return true;
        }
        b[x][y] = 0;
        bool ok = a[x][y] == 1;
        ok &= dfs(x - 1, y, a, b);
        ok &= dfs(x + 1, y, a, b);
        ok &= dfs(x, y - 1, a, b);
        ok &= dfs(x, y + 1, a, b);
        return ok;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int r = 0;
        for (int i = 0; i < grid2.size(); ++i) {
            for (int j = 0; j < grid2[i].size(); ++j) {
                if (grid2[i][j] && dfs(i, j, grid1, grid2)) {
                    ++r;
                }
            }
        }
        return r;
    }
};