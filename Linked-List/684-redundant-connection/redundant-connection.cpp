class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        set<pair<int, int>> cycle_edges;
        vector<int> path;
        unordered_map<int, int> node_to_index;
        vector<bool> visited(n + 1, false);
        bool found = false;

        function<void(int, int)> dfs = [&](int u, int parent) {
            if (found)
                return;
            visited[u] = true;
            path.push_back(u);
            node_to_index[u] = path.size() - 1;

            for (int v : adj[u]) {
                if (v == parent)
                    continue;
                if (!visited[v]) {
                    dfs(v, u);
                    if (found)
                        return;
                } else {
                    if (node_to_index.count(v)) {
                        int index = node_to_index[v];
                        for (int i = index; i < path.size() - 1; ++i) {
                            int a = path[i], b = path[i + 1];
                            cycle_edges.insert({min(a, b), max(a, b)});
                        }
                        cycle_edges.insert({min(u, v), max(u, v)});
                        found = true;
                        return;
                    }
                }
            }

            path.pop_back();
            node_to_index.erase(u);
        };

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                dfs(i, -1);
                if (found)
                    break;
            }
        }

        for (int i = edges.size() - 1; i >= 0; --i) {
            int a = edges[i][0], b = edges[i][1];
            pair<int, int> key = {min(a, b), max(a, b)};
            if (cycle_edges.count(key)) {
                return {a, b};
            }
        }

        return {};
    }
};