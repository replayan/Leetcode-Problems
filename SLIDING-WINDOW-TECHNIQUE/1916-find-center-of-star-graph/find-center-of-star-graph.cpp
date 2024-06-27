class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        /* o(n) TC and o(n) SC
        unordered_map<int, int> degree;
        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            degree[u]++;
            degree[v]++;
        }
        for (auto& it : degree) {
            if (it.second == size(edges)) {
                return it.first;
            }
        }
        return -1;
        */

        vector<int> first = edges[0];
        vector<int> second = edges[1];
        if (first[0] == second[0] || first[0] == second[1]) {
            return first[0];
        }
        return first[1];
    }
};