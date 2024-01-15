class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> lose(100001, -1);
        for (const auto& match : matches) {
            lose[match[0]] = max(lose[match[0]], 0);
            lose[match[1]] = max(lose[match[1]], 0) + 1;
        }
        vector<vector<int>> r(2);
        for (int i = 1; i <= 100000; ++i) {
            if (lose[i] == 0) {
                r[0].push_back(i);
            } else if (lose[i] == 1) {
                r[1].push_back(i);
            }
        }
        return r;
    }
};