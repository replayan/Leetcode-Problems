class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = ""; // To store the final output
        int count = 0; // Count of open parentheses encountered
        
        // Iterate through each character in the input string
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                // If an opening parenthesis is encountered, increment the count
                if (count > 0) {
                    // If count > 0, it means this parenthesis is not the outermost one
                    // So, add it to the result
                    result += c;
                }
                count++; // Increment the count of open parentheses
            } else {
                // If a closing parenthesis is encountered, decrement the count
                count--;
                if (count > 0) {
                    // If count > 0, it means this parenthesis is not the outermost one
                    // So, add it to the result
                    result += c;
                }
            }
        }
        return result;
    }
};
