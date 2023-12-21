class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // sort x coordinate
        vector<int> xCoordinates;
        for (const auto& point : points) {
            xCoordinates.push_back(point[0]);
        }
        sort(xCoordinates.begin(), xCoordinates.end());
        // maximum diff between consecutive x-co-or.
        int maxWidth = 0;
        for (int i = 1; i < xCoordinates.size(); ++i) {
            maxWidth = max(maxWidth, xCoordinates[i] - xCoordinates[i - 1]);
        }
        return maxWidth;
    }
};
