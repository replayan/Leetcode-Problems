class Solution {
public:
    int scoreOfString(string s) {
        // int n = size(s) - 1;
        int score = 0;
        for (int i = 0; s[i + 1] != '\0'; ++i) {
            score += abs(s[i] - s[i + 1]);
        }
        return score;
    }
};