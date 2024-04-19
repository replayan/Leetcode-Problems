class Solution {
    void dfs(vector<vector<char>>& g, int x, int y) {
        if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] != '1') return;
        g[x][y] = 'x';
        dfs(g, x - 1, y);
        dfs(g, x + 1, y);
        dfs(g, x, y - 1);
        dfs(g, x, y + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++r;
                    dfs(grid, i, j);
                }
            }
        }
        return r;
    }
};