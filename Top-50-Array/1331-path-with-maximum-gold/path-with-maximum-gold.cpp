class Solution {
    int dfs(vector<vector<int>> &g, int x, int y) {
        if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] == 0) {
            return 0;
        }
        const int temp = g[x][y];
        g[x][y] = 0;
        int r = 0;
        r = max(max(max(max(r, dfs(g, x - 1, y)), dfs(g, x + 1, y)), dfs(g, x, y - 1)), dfs(g, x, y + 1));
        g[x][y] = temp;
        return r + temp;
        
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int r = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                r = max(r, dfs(grid, i, j));
            }
        }
        return r;
        
    }
};