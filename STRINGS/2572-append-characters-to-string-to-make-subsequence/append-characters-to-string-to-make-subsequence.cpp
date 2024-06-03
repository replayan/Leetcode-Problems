class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = size(t);
        int m = size(s);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return n - j;
    }
};