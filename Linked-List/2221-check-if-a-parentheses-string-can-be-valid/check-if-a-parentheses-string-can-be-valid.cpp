class Solution {
public:
    bool canBeValid(string s, string locked) {
        const int n = s.length();
        if (n & 1) {
            return false;
        }
        int d = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ')' && locked[i] == '1') {
                if (--d < 0) {
                    return false;
                }
            } else {
                ++d;
            }
        }
        for (int i = n - 1, t = 0; d && i >= 0; --i) {
            if (s[i] == '(' && locked[i] == '1') {
                if (--t < 0) {
                    return false;
                }
            } else {
                ++t;
                if (locked[i] == '0') {
                    d -= 2;
                }
            }
        }
        return d == 0;
    }
};