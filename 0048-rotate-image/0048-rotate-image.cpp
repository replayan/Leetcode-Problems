class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> transposed(cols, vector<int>(rows));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed[j][i] = matrix[i][j];
            }
        }

        for (int i = 0; i < cols; i++) {
            int start = 0;
            int end = rows - 1;
            while (start < end) {
                int temp = transposed[i][start];
                transposed[i][start] = transposed[i][end];
                transposed[i][end] = temp;
                start++;
                end--;
            }
        }
        matrix = transposed;
    }
};
