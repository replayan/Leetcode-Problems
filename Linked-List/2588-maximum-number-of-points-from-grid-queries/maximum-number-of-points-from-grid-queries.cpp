class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> min_max(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        min_max[0][0] = grid[0][0];
        pq.emplace(grid[0][0], 0, 0);
        
        vector<int> dirs = {-1, 0, 1, 0, -1}; // Directions: up, right, down, left
        
        while (!pq.empty()) {
            auto [current_max, i, j] = pq.top();
            pq.pop();
            
            // Skip if a better path was already found for this cell
            if (current_max > min_max[i][j]) {
                continue;
            }
            
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirs[d];
                int nj = j + dirs[d + 1];
                
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    int new_max = max(current_max, grid[ni][nj]);
                    if (new_max < min_max[ni][nj]) {
                        min_max[ni][nj] = new_max;
                        pq.emplace(new_max, ni, nj);
                    }
                }
            }
        }
        
        // Collect all reachable cells' min_max values
        vector<int> reachable_min_max;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (min_max[i][j] != INT_MAX) {
                    reachable_min_max.push_back(min_max[i][j]);
                }
            }
        }
        sort(reachable_min_max.begin(), reachable_min_max.end());
        
        // Process each query
        vector<int> answer;
        for (int q : queries) {
            if (q <= grid[0][0]) {
                answer.push_back(0);
            } else {
                // Number of elements less than q is the upper_bound of q-1
                auto it = upper_bound(reachable_min_max.begin(), reachable_min_max.end(), q - 1);
                answer.push_back(it - reachable_min_max.begin());
            }
        }
        
        return answer;
    }
};