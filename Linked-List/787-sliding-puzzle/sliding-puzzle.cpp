class Solution {
    const vector<vector<int>> want = {{1, 2, 3}, {4, 5, 0}};
    const vector<int> dx = {0, 1, 0, -1};
    const vector<int> dy = {1, 0, -1, 0};
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        map<vector<vector<int>>, int> d;
        d[board] = 0;
        queue<vector<vector<int>>> q;
        for (q.push(board); !q.empty() && d.count(want) == 0;) {
            auto v = q.front();
            q.pop();
            int x = 0, y = 0, s = d[v] + 1;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (v[i][j] == 0) {
                        x = i;
                        y = j;
                    }
                }
            }
            //printf("x = %d y = %d\n", x, y);
            for (int i = 0; i < 4; ++i) {
                //printf("i = %d", i);
                const int xx = x + dx[i], yy = y + dy[i];
                if (xx >= 0 && xx < 2 && yy >= 0 && yy < 3 && v[xx][yy]) {
                    //printf("xx = %d yy = %d\n", xx, yy);
                    swap(v[xx][yy], v[x][y]);
                    if (d.count(v) == 0) {
                        d[v] = s;
                        q.push(v);
                    }
                    swap(v[xx][yy], v[x][y]);
                }
            }
        } 
        return d.count(want) ? d[want] : -1;
    }
};