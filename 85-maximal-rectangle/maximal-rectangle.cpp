class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0; // If the matrix is empty, return 0

        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns
        vector<int> heights(n, 0); // Vector to store heights of consecutive 1's in each column
        int maxArea = 0; // Variable to store the maximum area of the rectangle

        for (int i = 0; i < m; ++i) { // Iterate over each row
            // Update the heights vector based on the current row
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1; // If the current cell is '1', increment the height
                } else {
                    heights[j] = 0; // If the current cell is '0', reset the height to 0
                }
            }

            // Find the maximum area rectangle with the current heights
            maxArea = max(maxArea, findMaxAreaWithHeights(heights, n));
        }
        return maxArea;
    }

private:
    int findMaxAreaWithHeights(vector<int>& heights, int n) {
        stack<int> st; 
        int maxArea = 0; // to store the maximum area of the rectangle
        int top; 

        for (int i = 0; i <= n; ++i) { // Iterate over the heights vector (including a sentinel value)
            // When the current height is 0 (end of rectangle) or we reach the end
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                // Calculate the area with the current height as the smallest
                top = st.top();
                st.pop();
                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                int area = heights[top] * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        return maxArea;
    }
};