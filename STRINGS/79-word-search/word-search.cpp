class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(); // Get the number of rows in the board
        int n = board[0].size(); // Get the number of columns in the board

        // Iterate over each cell in the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Call the dfs function starting from the current cell
                if (dfs(board, word, 0, i, j)) {
                    return true; // Return true if the word is found
                }
            }
        }

        return false; // Return false if the word is not found
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int idx, int i, int j) {
        // Base case: If idx is equal to the length of the word, it means we have matched all characters
        if (idx == word.length()) {
            return true;
        }

        // Check if the current cell is out of bounds or if the character in the cell doesn't match the current character in the word
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }

        // Mark the current cell as visited by changing its value to a special character (e.g., '#')
        board[i][j] = '#';

        // Recursively explore the neighboring cells (up, down, left, right)
        bool found = dfs(board, word, idx + 1, i + 1, j) || // Explore the cell below
                     dfs(board, word, idx + 1, i - 1, j) || // Explore the cell above
                     dfs(board, word, idx + 1, i, j + 1) || // Explore the cell to the right
                     dfs(board, word, idx + 1, i, j - 1);   // Explore the cell to the left

        // Restore the original character in the current cell (backtrack)
        board[i][j] = word[idx];

        return found;
    }
};