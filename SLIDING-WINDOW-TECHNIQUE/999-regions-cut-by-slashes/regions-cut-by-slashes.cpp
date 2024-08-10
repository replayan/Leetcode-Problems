class Solution {
    int left(int x, int y, int n) {
        return (x * n + y) << 1;
    }

    int right(int x, int y, int n) {
        return left(x, y, n) | 1;
    }

    int getf(vector<int> &f, int x) {
        return f[x] == x ? x : (f[x] = getf(f, f[x]));
    }

    bool merge(int x, int y, vector<int> &f, vector<int> &num) {
        x = getf(f, x);
        y = getf(f, y);
        if (x == y) {
            return false;
        }
        if (num[x] > num[y]) {
            swap(x, y);
        }
        f[x] = y;
        num[y] += num[x];
        return true;
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        const int m = grid.size(), n = grid[0].size(), mn = m * n * 2;
        vector<int> f(mn), num(mn);
        for (int i = 0; i < mn; ++i) {
            f[i] = i;
            num[i] = 1;
        }
        int r = mn;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                switch(grid[i][j]) {
                    case ' ':
                        r -= merge(left(i, j, n), right(i, j, n), f, num);
                        if (i) {
                            r -= merge(grid[i - 1][j] == '\\' ? left(i - 1, j, n) : right(i - 1, j, n), left(i, j, n), f, num);
                        }
                        break;
                    case '/':
                        if (i) {
                            r -= merge(grid[i - 1][j] == '\\' ? left(i - 1, j, n) : right(i - 1, j, n), left(i, j, n), f, num);
                        }
                        break;
                    case '\\':
                        if (i) {
                            r -= merge(grid[i - 1][j] == '\\' ? left(i - 1, j, n) : right(i - 1, j, n), right(i, j, n), f, num);
                        }
                        break;
                }
                if (j) {
                     r -= merge(right(i, j - 1, n), left(i, j, n), f, num);
                }

            }
        }
        return r;
        
    }
};