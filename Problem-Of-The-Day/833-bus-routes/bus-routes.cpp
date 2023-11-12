class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) {
            return 0;
        }
        int n = routes.size();
        vector<bool> in(n), out(n);
        vector<vector<bool>> g(n, vector<bool>(n));
        vector<vector<int>> con(1000000);
        vector<int> b(n, -1);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            for (int x : routes[i]) {
                for (int y : con[x]) {
                    g[i][y] = g[y][i] = true;
                }
                con[x].push_back(i);
                if (x == S) {
                    in[i] = true;
                    if (out[i]) {
                        return 1;
                    }
                    q.push(i);
                    b[i] = 1;
                }
                if (x == T) {
                    out[i] = true;
                    if (in[i]) {
                        return 1;
                    }
                }
            }
        }
        for (; !q.empty(); ) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < n; ++i) {
                if (g[x][i] && b[i] < 0) {
                    b[i] = b[x] + 1;
                    if (out[i]) {
                        return b[i];
                    }
                    q.push(i);
                }
            }
        }
        return -1;
    }
};