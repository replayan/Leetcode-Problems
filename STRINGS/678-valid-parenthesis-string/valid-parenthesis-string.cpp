class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else if (c == '*') {
                minOpen--;
                maxOpen++;
            }

            // If the number of '(' is smaller than the number of ')'
            if (maxOpen < 0)
                return false;

            // If the number of '(' is greater than the number of ')'
            if (minOpen < 0)
                minOpen = 0;
        }
        return minOpen == 0;
    }
};