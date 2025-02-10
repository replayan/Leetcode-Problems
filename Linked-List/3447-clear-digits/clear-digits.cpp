class Solution {
public:
    string clearDigits(string s) {
        string result;
        for (char c : s) {
            if (isdigit(c)) {
                // When a digit is encountered, remove the last character if available.
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                // Otherwise, append the non-digit character.
                result.push_back(c);
            }
        }
        return result;
    }
};
