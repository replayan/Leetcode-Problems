class Solution {

public:
    int longestSubsequence(string s, int k) {
        int r = 0;
        for (int w = 1, v = 0; v <= k && !s.empty();
             w = w > k ? w : (w << 1), s.pop_back()) {
            if (s.back() == '1') {
                v |= w;
                if (v > k) {
                    v ^= w;
                    continue;
                }
            }
            ++r;
        }
        return r;
    }
};