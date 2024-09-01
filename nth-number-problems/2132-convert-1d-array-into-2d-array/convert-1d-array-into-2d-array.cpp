class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int k = original.size();
        vector<vector<int>> mat(m, vector<int>(n));
        if (k != m * n) {
            return {}; // empty array return
        }
        int index = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = original[index];
                index++;
            }
        }
        return mat;
    }
};