class Solution {
public:
    int minChanges(string s) {
        int r = 0;
        for (int i = 1; i < s.length(); i += 2) {
            r += s[i] != s[i - 1];
        }
        return r;
    }
};