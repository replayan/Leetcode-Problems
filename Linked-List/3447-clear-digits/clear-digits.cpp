class Solution {
public:
    string clearDigits(string s) {
        int j = 0; // 'j' acts as the stack pointer.
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            // Instead of using isdigit(c), we use a direct range check.
            if (c >= '0' && c <= '9') {
                if (j > 0) {
                    // "Pop" the last non-digit character.
                    --j;
                }
            } else {
                // "Push" the non-digit character onto our in-place stack.
                s[j++] = c;
            }
        }
        s.resize(j); // Resize the string to contain only the valid characters.
        return s;
    }
};
