class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> v(m - 2, vector<int>(n - 2));
        for (int i = 1; i + 1 < grid.size(); ++i) {
            for (int j = 1; j + 1 < grid[i].size(); ++j) {
                for (int x = -1; x <= 1; ++x) {
                    for (int y = -1; y <= 1; ++y) {
                        v[i - 1][j - 1] = max(v[i - 1][j - 1], grid[i + x][j + y]);
                    }
                }
            }
        }
        return v;
        
    }
};