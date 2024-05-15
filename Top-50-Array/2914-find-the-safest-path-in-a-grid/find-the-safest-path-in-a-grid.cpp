// credit : neetcodeIO

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        queue<int> q;
        const int n = grid.size();
        vector<vector<int>> d(n, vector<int>(n, -1));
        bool ath = false;
        for (int i = 0; i < n; ++i) {
            assert(grid[i].size() == n);
            for (int j = 0; j < n; ++j) {
                assert(grid[i][j] == 0 || grid[i][j] == 1);
                if (grid[i][j]) {
                    q.push((i << 10) | j);
                    d[i][j] = 0;
                    ath = true;
                }
            }
        }
        assert(ath);
        while (!q.empty()) {
            const int x = q.front() >> 10, y = q.front() & 1023;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                const int xx = x + dx[i], yy = y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && d[xx][yy] < 0) {
                    d[xx][yy] = d[x][y] + 1;
                    q.push((xx << 10) | yy);
                }
            }
        }
        vector<vector<int>> mark(n, vector<int>(n, -1));
        priority_queue<pair<int, int>> pq;
        pq.push({d[0][0], 0});
        while (!pq.empty()) {
            const int x = pq.top().second >> 10, y = pq.top().second & 1023, p = pq.top().first;
            pq.pop();
            if (mark[x][y] >= 0) {
                continue;
            }
            if (x == n - 1 && y == n - 1) {
                return p;
            }
            mark[x][y] = p;
            for (int i = 0; i < 4; ++i) {
                const int xx = x + dx[i], yy = y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < n) {
                    pq.push({min(p, d[xx][yy]), (xx << 10) | yy});
                }
            }
        }
        return -1;
    }
};