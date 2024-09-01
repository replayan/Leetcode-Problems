class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // m is row and n is column
        int k = size(original);
        vector<vector<int>> mat(m, vector<int>(n));
        if (m * n != k) {
            return {}; // if Inconsistent Lengths return empty array
        }
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = original[idx];
                idx += 1;
            }
        }
        return mat;
    }
};