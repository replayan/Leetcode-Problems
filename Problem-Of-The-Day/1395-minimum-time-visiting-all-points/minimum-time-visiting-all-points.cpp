class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int min_time = 0;
        for (int i=0; i<points.size()-1; ++i) {
            int x = points[i][0];
            int y = points[i][1];
            int a = points[i + 1][0];
            int b = points[i + 1][1];
            min_time += max(abs(a-x),abs(b-y));
        }
        return min_time;
    }
};
