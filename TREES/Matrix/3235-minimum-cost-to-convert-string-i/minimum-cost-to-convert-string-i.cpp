class Solution {
    int get(const vector<vector<pair<int, int>>>& con, int from, int to) {
        vector<bool> mark(26);
        vector<int> d(26, -1);
        priority_queue<pair<int, int>> q;
        q.push({0, from});
        d[from] = 0;
        while (!q.empty()) {
            const int c = -q.top().first, x = q.top().second;
            q.pop();
            if (mark[x]) continue;
            mark[x] = true;
            if (x == to) break;
            for (const auto& p : con[x]) {
                const int may = c + p.second;
                if (d[p.first] < 0 || d[p.first] > may) {
                    d[p.first] = may;
                    q.push({-may, p.first});
                }
            }
        }
        return d[to];
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> con(26);
        const int m = cost.size();
        for (int i = 0; i < m; ++i) {
            con[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        const int n = source.size();
        long long r = 0;
        vector<vector<int>> have(26, vector<int>(26, -1));
        for (int i = 0; i < n; ++i) {
            const int from = source[i] - 'a', to = target[i] - 'a';
            if (have[from][to] < 0) {
                have[from][to] = get(con, from, to);
            }
            if (have[from][to] < 0) return -1;
            r += have[from][to];
        }
        return r;
    }
};