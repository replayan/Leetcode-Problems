//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfsOrder; // To store the BFS traversal order.
        vector<bool> visited(V, false); // To mark visited vertices.

        // Create a queue for BFS.
        queue<int> q;

        // Start BFS from the first vertex (0) if it exists in the graph.
        if (V > 0) {
            q.push(0); // Push the first vertex into the queue.
            visited[0] = true; // Mark the first vertex as visited.
        }

        // Perform BFS traversal.
        while (!q.empty()) {
            int currVertex = q.front();
            q.pop();

            bfsOrder.push_back(currVertex); // Add the current vertex to the BFS order.

            // Traverse all adjacent vertices of the current vertex.
            for (int neighbor : adj[currVertex]) {
                if (!visited[neighbor]) {
                    q.push(neighbor); // Add unvisited neighbors to the queue.
                    visited[neighbor] = true; // Mark the neighbor as visited.
                }
            }
        }

        return bfsOrder;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends