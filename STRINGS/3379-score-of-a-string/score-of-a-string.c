int scoreOfString(char *s) {
    int n = strlen(s) - 1;
    int score = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] > s[i + 1]) {
            score += s[i] - s[i + 1];
        } else {
            score += s[i + 1] - s[i];
        }
    }
    return score;
}