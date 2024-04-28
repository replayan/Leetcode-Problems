class Solution {
public:
    int dfs(int lev, int x, int f, vector<int>& num, const vector<vector<int>>& con) {
        int r = lev;
        num[x] = 1;
        for (int y : con[x]) {
            if (y != f) {
                r += dfs(lev + 1, y, x, num, con);
                num[x] += num[y];
            }
        }
        return r;
    }

    void dfs(int x, int f, vector<int>& s, const vector<int>& num, vector<vector<int>>& con) {
        if (f >= 0) {
            s[x] = s[f] - num[x] + (s.size() - num[x]);
        }
        for (int y : con[x]) {
            if (y != f) {
                dfs(y, x, s, num, con);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> con(N);
        for (const auto& e : edges) {
            con[e[0]].push_back(e[1]);
            con[e[1]].push_back(e[0]);
        }
        vector<int> num(N), s(N);
        s[0] = dfs(0, 0, -1, num, con);
        dfs(0, -1, s, num, con);
        return s;
    }
};