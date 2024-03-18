class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), points.end());
        int count = 1;
        vector<int> prev = points[0];
        for (int i = 1; i < points.size(); i++) {
            int currSP = points[i][0];
            int currEP = points[i][1];
            int prevSP = prev[0];
            int prevEP = prev[1];
            if (currSP > prevEP) {
                count++;
                prev = points[i];
            } else {
                prev[0] = max(currSP, prevSP);
                prev[1] = min(currEP, prevEP);
            }
        }
        return count;
    }
};