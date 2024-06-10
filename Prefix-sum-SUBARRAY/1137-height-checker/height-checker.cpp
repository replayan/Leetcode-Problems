class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> clonedHeights = heights;

        sort(begin(clonedHeights), end(clonedHeights));

        int count = 0;
        for (int i = 0; i < heights.size(); ++i) {
            count += heights[i] != clonedHeights[i];
        }
        return count;
    }
};