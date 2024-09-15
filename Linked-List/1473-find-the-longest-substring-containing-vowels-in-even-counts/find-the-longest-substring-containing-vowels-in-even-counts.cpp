class Solution {
    const char* p = "aeiou";
    int mask(char c) {
        const char *t = strchr(p, c);
        return t == nullptr ? 0 : (1 << (t - p));
    }
public:
    int findTheLongestSubstring(string s) {
        vector<int> have(32, -1);
        int r = have[0] = 0;
        for (int i = 1, j = 0; i <= s.length(); ++i) {
            j ^= mask(s[i - 1]);
            if (have[j] < 0) {
                have[j] = i;
            } else {
                r = max(r, i - have[j]);
            }
        }
        return r;
        
    }
};