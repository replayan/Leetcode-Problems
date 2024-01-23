class Solution {
    void dfs(const vector<string>& a, int ind, int state, int maybe,
             int& best) {
        if (best == 26 || ind >= a.size()) {
            best = max(maybe, best);
            return;
        }
        dfs(a, ind + 1, state, maybe, best);
        for (char c : a[ind]) {
            const int mask = 1 << (c - 'a');
            if (state & mask) {
                return;
            }
            state |= mask;
        }
        dfs(a, ind + 1, state, maybe + a[ind].length(), best);
    }

public:
    int maxLength(vector<string>& arr) {
        int r = 0;
        dfs(arr, 0, 0, 0, r);
        return r;
    }
};