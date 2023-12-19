class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> r(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = 0;
                for (int x = max(-1, -i); x <= 1 && i + x < m; ++x) {
                    for (int y = max(-1, -j); y <= 1 && j + y < n; ++y) {
                        t+=1;
                        r[i][j] += img[x + i][y + j];
                    }
                }
                r[i][j] /= t;
            }
        }
        return r;
    }
};