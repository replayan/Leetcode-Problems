class Solution {
public:
    int lengthOfLastWord(string s) {
        int length_of_last_word = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                ++length_of_last_word;
            } else if (length_of_last_word > 0) {
                break;
            }
        }
        return length_of_last_word;
    }
};