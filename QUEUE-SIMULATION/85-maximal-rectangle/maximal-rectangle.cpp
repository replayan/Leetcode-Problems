class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0; // Handle empty matrix
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0); // Store heights of consecutive '1's
        int maxArea = 0;
        
        for (int i = 0; i < m; ++i) {
            // Update heights based on current row
            for (int j = 0; j < n; ++j) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }
            
            // Find maximum area rectangle with current heights
            maxArea = max(maxArea, maxAreaWithHeights(heights));
        }
        
        return maxArea;
    }
    
private:
    int maxAreaWithHeights(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // Store indices
        int maxArea = 0, top;
        
        for (int i = 0; i <= n; ++i) {
            // When current height is 0 (end of rectangle) or we reach the end
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                // Calculate area with the current height as the smallest
                top = st.top();
                st.pop();
                maxArea = max(maxArea, heights[top] * (st.empty() ? i : i - st.top() - 1));
            }
            
            st.push(i); // Push the current index
        }
        
        return maxArea;
    }
};