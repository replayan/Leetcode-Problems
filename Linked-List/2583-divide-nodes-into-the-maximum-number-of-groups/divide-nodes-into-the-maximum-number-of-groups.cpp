class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> component(n + 1, -1);
        vector<vector<int>> components;

        // Finding connected components using BFS
        for (int i = 1; i <= n; ++i) {
            if (component[i] != -1)
                continue;

            vector<int> comp;
            queue<int> q;
            q.push(i);
            component[i] = components.size();

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                comp.push_back(node);

                for (int neighbor : adj[node]) {
                    if (component[neighbor] == -1) {
                        component[neighbor] = component[i];
                        q.push(neighbor);
                    }
                }
            }
            components.push_back(comp);
        }

        int maxGroups = 0;

        // Process each component to determine the max depth using BFS
        for (const auto& comp : components) {
            int maxDepth = -1;
            for (int node : comp) {
                vector<int> dist(n + 1, -1);
                queue<int> q;
                q.push(node);
                dist[node] = 0;
                int depth = 0;

                while (!q.empty()) {
                    int size = q.size();
                    ++depth;
                    for (int i = 0; i < size; ++i) {
                        int curr = q.front();
                        q.pop();
                        for (int neighbor : adj[curr]) {
                            if (dist[neighbor] == -1) {
                                dist[neighbor] = dist[curr] + 1;
                                q.push(neighbor);
                            } else if (abs(dist[neighbor] - dist[curr]) != 1) {
                                return -1; // Not possible to group
                            }
                        }
                    }
                }
                maxDepth = max(maxDepth, depth);
            }
            maxGroups += maxDepth;
        }

        return maxGroups;
    }
};