class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the distance matrix with a large value (infinity)
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Distance from a city to itself is always 0
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        // Fill initial distances from edges
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            dist[from][to] = weight;
            dist[to][from] = weight;
        }

        // Floyd-Warshall algorithm to find shortest paths between all pairs of cities
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Find the city with the smallest number of reachable cities within the distance threshold
        int resultCity = -1;
        int minReachableCities = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    ++reachableCities;
                }
            }

            // Updating the result based on the number of reachable cities
            if (reachableCities < minReachableCities || 
                (reachableCities == minReachableCities && i > resultCity)) {
                minReachableCities = reachableCities;
                resultCity = i;
            }
        }
        return resultCity;
    }
};
