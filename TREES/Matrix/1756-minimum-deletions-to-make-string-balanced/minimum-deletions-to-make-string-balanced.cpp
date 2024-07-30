class Solution {
public:
    int minimumDeletions(string s) {
        int num_a = 0;
        for (char c : s) {
            num_a += c == 'a';
        }
        int curr_a = 0;
        const int n = s.length();
        int r = n - num_a;
        for (int i = 0; i < n; ++i) {
            r = min(r, (i - curr_a) + (num_a - curr_a));
            curr_a += s[i] == 'a';
        }
        return r;
    }
};