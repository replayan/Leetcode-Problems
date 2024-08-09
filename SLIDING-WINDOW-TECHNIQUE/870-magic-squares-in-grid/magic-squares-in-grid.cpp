class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int r = 0;
        for (int i = 0; i + 3 <= m; ++i) {
            for (int j = 0; j + 3 <= n; ++j) {
                vector<bool> mark(16);
                bool ok = true;
                for (int x = 0; ok && x < 3; ++x) {
                    int s = 0;
                    for (int y = 0; s <= 15 && ok && y < 3; ++y) {
                        const int temp = grid[i + x][j + y];
                        ok = temp >= 1 && temp <= 9 && !mark[temp];
                        mark[temp] = true;
                        s += temp;
                    }
                    ok = ok && (s == 15);
                }
                for (int x = 0; ok && x < 3; ++x) {
                    int s = 0;
                    for (int y = 0; s <= 15 && y < 3; ++y) {
                        s += grid[i + y][j + x];
                    }
                    ok = s == 15;
                }
                int s = 0;
                for (int x = 0; s <= 15 && ok && x < 3; ++x) {
                    s += grid[i + x][j + x];
                }
                ok = ok && (s == 15);
                s = 0;
                for (int x = 0; s <= 15 && ok && x < 3; ++x) {
                    s += grid[i + x][j + 2 - x];
                }
                if (ok && s == 15) {
                    ++r;
                }

            }
        }
        return r;
        
    }
};