class Solution {
     const int M = 1000000007;
     void add(int &x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
        
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3)));
        // A -- 0, P -- 1, L --2
        // dp[len][has A?][length of L]
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (dp[i - 1][j][k]) {
                       for (int x = (k == 2) ? 1 : 2; x >= j; --x) {
                           add(dp[i][j || !x][x == 2 ? (k + 1) : 0], dp[i - 1][j][k]);
                       }
                    }
                }
            }
        }
        int r = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                add(r, dp[n][j][k]);
            }
        }
        return r;

    }
};