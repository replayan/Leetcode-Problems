#include <vector>
using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> component_AND;

    UnionFind(int n) {
        parent.resize(n);
        component_AND.resize(n, -1); // -1 means all bits set (no edges yet)
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSet(int x, int y, int w) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            component_AND[rootY] = component_AND[rootX] & component_AND[rootY] & w;
        } else {
            component_AND[rootY] &= w; // Update within the same component
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind uf(n);

        // Process all edges to build components and compute ANDs
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            uf.unionSet(u, v, w);
        }

        // Process each query
        vector<int> answer;
        for (const auto& q : query) {
            int s = q[0];
            int t = q[1];
            int rootS = uf.find(s);
            int rootT = uf.find(t);
            if (rootS != rootT) {
                answer.push_back(-1); // Different components, no walk possible
            } else {
                answer.push_back(uf.component_AND[rootS]); // Same component, use precomputed AND
            }
        }
        return answer;
    }
};