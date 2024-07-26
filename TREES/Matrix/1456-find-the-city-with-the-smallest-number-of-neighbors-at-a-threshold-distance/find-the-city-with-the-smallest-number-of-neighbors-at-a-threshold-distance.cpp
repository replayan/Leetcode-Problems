class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Step 1: Initialize the distance matrix with a large value (10001, greater than any possible path length)
        vector<vector<int>> dis(n, vector<int>(n, 10001));
        
        // Step 2: Set the distance for each edge in the graph
        for (const auto& e : edges) {
            dis[e[0]][e[1]] = e[2];
            dis[e[1]][e[0]] = e[2];
        }
        
        // Step 3: Distance from a city to itself is always 0
        for (int i = 0; i < n; ++i) {
            dis[i][i] = 0;
        }
        
        // Step 4: Floyd-Warshall algorithm to find the shortest paths between all pairs of cities
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        
        // Step 5: Find the city with the smallest number of reachable cities within the distance threshold
        int resultCity = 0;
        int smallestReachable = n;
        
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (dis[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            
            // If count is less than the smallest, update resultCity and smallestReachable
            // If count is equal to the smallest, choose the city with the greatest index
            if (count < smallestReachable || (count == smallestReachable && i > resultCity)) {
                resultCity = i;
                smallestReachable = count;
            }
        }
        return resultCity;
    }
};