class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1)); // Initialize result matrix with -1
        
        queue<pair<int, int>> q;
        
        // Initialize the queue with the positions of all zeros
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Define possible directions (up, down, left, right)
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        // Perform BFS
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; ++k) {
                int newX = x + dx[k];
                int newY = y + dy[k];
                
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && result[newX][newY] == -1) {
                    result[newX][newY] = result[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
        return result;
    }
};
