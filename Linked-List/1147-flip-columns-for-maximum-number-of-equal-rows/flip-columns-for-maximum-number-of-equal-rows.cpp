class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> have;
        int r = 0;
        for (const auto& row : matrix) {
            string t;
            for (int x : row) {
                t += (x == row[0] ? 1 : 0) + '0';
            }
            r = max(r, ++have[t]);
        }
        return r;
    }
};