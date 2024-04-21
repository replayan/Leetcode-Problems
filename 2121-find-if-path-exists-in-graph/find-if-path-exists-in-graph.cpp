class Solution {
    bool dfs(const int from, const int to, const vector<vector<int>> &con, const int x, vector<bool> &v) {
        if (v[x]) {
            return false;
        }
        v[x] = true;
        if (x == to) {
            return true;
        }
        for (auto y : con[x]) {
            if (dfs(from, to, con, y, v)) {
                return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> con(n);
        for (const auto& e : edges) {
            con[e[0]].push_back(e[1]);
            con[e[1]].push_back(e[0]);
        }
        vector<bool> v(n);
        return dfs(start, end, con, start, v);
        
    }
};