class Graph {
private:
    int numNodes;
    unordered_map<int, vector<pair<int, int>>> adjacencyList;

public:
    Graph(int n, vector<vector<int>>& edges) {
        numNodes = n;

        // Build the adjacency list
        for (const vector<int>& edge : edges) {
            addEdge(edge);
        }
    }

    void addEdge(vector<int> edge) {
        int node1 = edge[0];
        int node2 = edge[1];
        int cost = edge[2];

        adjacencyList[node1].push_back({node2, cost});
    }

    int shortestPath(int node1, int node2) {
        vector<int> distances(numNodes, INT_MAX);
        distances[node1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});

        while (!pq.empty()) {
            int currentDistance = pq.top().first;
            int current = pq.top().second;
            pq.pop();

            if (currentDistance > distances[current]) {
                continue;
            }

            for (const pair<int, int>& neighbor : adjacencyList[current]) {
                int neighborNode = neighbor.first;
                int edgeCost = neighbor.second;

                int newDistance = distances[current] + edgeCost;
                if (newDistance < distances[neighborNode]) {
                    distances[neighborNode] = newDistance;
                    pq.push({newDistance, neighborNode});
                }
            }
        }
        return distances[node2] == INT_MAX ? -1 : distances[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1, node2);
 */
