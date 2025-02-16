class Solution {
    bool dfs(vector<int>& v, int ind, int mask, int n) {
        for (; ind < v.size() && v[ind]; ++ind)
            ;
        if (ind >= v.size()) {
            return true;
        }
        for (int i = n; i; --i) {
            if (mask & (1 << i)) {
                continue;
            }
            if (i == 1 || (ind + i < v.size() && v[ind + i] == 0)) {
                v[ind] = i;
                if (i > 1) {
                    v[ind + i] = i;
                }
                if (dfs(v, ind + 1, mask | (1 << i), n)) {
                    return true;
                }
                v[ind] = 0;
                if (i > 1) {
                    v[ind + i] = 0;
                }
            }
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> v(n * 2 - 1);
        dfs(v, 0, 0, n);
        return v;
    }
};