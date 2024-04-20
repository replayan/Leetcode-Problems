class Solution {
    void dfs(vector<vector<int>>& land, int x, int y, vector<vector<int>>& v) {
        if (x < 0 || x >= land.size() || y < 0 || y >= land[x].size() || land[x][y] == 0) {
            return;
        }
        land[x][y] = 0;
        switch(v.size()) {
            case 0:
                v.push_back({x, y});
                break;
            case 1:
                v.push_back({x, y});
                if (v[0] > v[1]) {
                    swap(v[0], v[1]);
                }
                break;
            default:
                const vector<int> temp = {x, y};
                if (temp < v[0]) {
                    v[0] = temp;
                } else if (temp > v[1]) {
                    v[1] = temp;
                }
                break;
        }
        dfs(land, x - 1, y, v);
        dfs(land, x + 1, y, v);
        dfs(land, x, y - 1, v);
        dfs(land, x, y + 1, v);
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> r;
        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[i].size(); ++j) {
                if (land[i][j]) {
                    vector<vector<int>> all;
                    dfs(land, i, j, all);
                    r.push_back({(*all.begin())[0], (*all.begin())[1], all.back()[0], all.back()[1]});
                }
                
            }
        }
        return r;
    }
};