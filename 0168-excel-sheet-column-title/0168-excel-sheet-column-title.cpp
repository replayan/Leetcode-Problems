class Solution {
public:
    string convertToTitle(int columnNumber) {
        string column_title = "";
        
        while (columnNumber > 0) {
            int remainder = (columnNumber - 1) % 26;
            column_title = char('A' + remainder) + column_title;
            columnNumber = (columnNumber - 1) / 26;
        }
        return column_title;
    }
};
