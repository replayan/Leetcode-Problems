class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.length();
        int r = 0;
        for (int i = 0; i < n; ++i) {
            for (int x = i - 1, y = i; x >= 0 && y < n && s[x] == s[y];
                 --x, ++y, ++r)
                ;
            for (int x = i, y = i; x >= 0 && y < n && s[x] == s[y];
                 --x, ++y, ++r)
                ;
        }
        return r;
    }
};
