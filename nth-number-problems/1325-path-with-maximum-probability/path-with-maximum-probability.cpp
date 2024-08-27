class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> con(n);
        for (int i = 0; i < edges.size(); ++i) {
            con[edges[i][0]].push_back({edges[i][1], succProb[i]});
            con[edges[i][1]].push_back({edges[i][0], succProb[i]});
            
        }
        vector<int> r(n, -1234);
        priority_queue<pair<double, int>> q;
        for (q.push({1, start}); !q.empty();) {
            const double now = q.top().first;
            const int x = q.top().second;
            q.pop();
            if (x == end) return now;
            if (r[x] > -.5) continue;
            r[x] = now;
            for (const auto& e : con[x]) {
                if (r[e.first] < -1) q.push({now * e.second, e.first});
            }
        }
        return 0;
        
    }
};