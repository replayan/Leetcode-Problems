class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int r = 0, score = 0;
        sort(tokens.begin(), tokens.end());
        for (int i = 0, j = tokens.size() - 1; i <= j;) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                r = max(r, ++score);
            } else if (score >= 1) {
                --score;
                power += tokens[j--];
            } else {
                break;
            }
        }
        return r;
    }
};