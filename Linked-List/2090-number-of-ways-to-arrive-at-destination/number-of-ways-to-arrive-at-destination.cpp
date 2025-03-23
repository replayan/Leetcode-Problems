class Solution {
    const int M = 1000000007;
    void add(int &x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> con(n);
        for (const auto& road : roads) {
            con[road[0]].push_back({road[1], road[2]});
            con[road[1]].push_back({road[0], road[2]});
        }
        vector<bool> mark(n);
        vector<long long> mini(n, -1);
        vector<int> num(n);
        num[0] = 1;
        mini[0] = 0;
        priority_queue<vector<long long>> q;
        for (q.push({0, 0}); !mark.back();) {
            const int x = q.top()[1];
            const long long d = -q.top()[0];
            q.pop();
            if (mark[x]) {
                continue;
            }
            mark[x] = true;
            for (const auto& v : con[x]) {
                const int y = v[0];
                const long long dd = d + v[1];
                if (mini[y] < 0 || dd < mini[y]) {
                    mini[y] = dd;
                    num[y] = num[x];
                    q.push({-dd, y});
                } else if (dd == mini[y]) {
                    add(num[y], num[x]);
                }
            }
        }
        return num.back();
        
    }
};