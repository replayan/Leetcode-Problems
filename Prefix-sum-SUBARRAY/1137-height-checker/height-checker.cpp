class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> clonedHeights(heights.size());
        copy(heights.begin(), heights.end(), clonedHeights.begin());
        sort(begin(clonedHeights), end(clonedHeights));
        int count = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != clonedHeights[i]) {
                count++;
            }
        }
        return count;
    }
};