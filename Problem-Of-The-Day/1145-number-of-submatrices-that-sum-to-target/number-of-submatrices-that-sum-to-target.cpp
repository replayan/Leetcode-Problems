class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = 0;
        for (int i = 0; i < matrix[0].size(); ++i) {
            vector<int> v(matrix.size());
            for (int j = i; j < matrix[0].size(); ++j) {
                unordered_map<int, int> have;
                ++have[0];
                for (int k = 0, sum = 0; k < matrix.size(); ++k) {
                    v[k] += matrix[k][j];
                    sum += v[k];
                    const auto t = have.find(sum - target);
                    if (t != have.end()) {
                        r += t->second;
                    }
                    ++have[sum];
                }
            }
        }
        return r;
    }
};