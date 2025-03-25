class Solution {
    bool check(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int last = -1, c = 0;
        for (const auto& p : v) {
            if (p[0] >= last) {
                if (++c == 3)
                    return true;
                last = p[1];
            } else {
                last = max(last, p[1]);
            }
        }
        return false;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x, y;
        for (const auto& v : rectangles) {
            x.push_back({v[0], v[2]});
            y.push_back({v[1], v[3]});
        }
        return check(x) || check(y);
    }
};
