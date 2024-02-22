class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in(N), out(N);
        for (const auto& v : trust) {
            ++in[v[1] - 1];
            ++out[v[0] - 1];
        }
        int ind = -1;
        for (int i = 0; i < N; ++i) {
            if (out[i] == 0 && in[i] == N - 1) {
                if (ind >= 0) return -1;
                ind = i + 1;
            }
        }
        return ind;
    }
};