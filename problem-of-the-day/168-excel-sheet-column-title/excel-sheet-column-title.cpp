class Solution {
public:
    string convertToTitle(int columnNumber) {
        // Initialize an empty string to store the column title
        string column_title = "";
        
        // Loop until the column number becomes 0
        while (columnNumber > 0) {
            // Calculate the remainder when subtracting 1 and then dividing by 26
            int remainder = (columnNumber - 1) % 26;

            // Convert the remainder to a letter ('A' + remainder)
            char letter = 'A' + remainder;

            // Add the letter to the beginning of the column title
            column_title = letter + column_title;

            // Reduce the column number for the next iteration
            columnNumber = (columnNumber - 1) / 26;
        }
        // Return the constructed column title
        return column_title;
    }
};
