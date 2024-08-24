class Solution {
    string make1(const string &n) {
        const int m = n.length();
        string s = n;
        for (int i = 0, j = m - 1; i <= j; s[j--] = s[i++])
        ;
        if (s < n) {
            return s;
        }
        for (int i = (m - 1) >> 1; i >= 0; --i) {
            if (s[i] == '0') {
                continue;
            }
            if (i > 0 || s[i] > '1') {
                s[m - 1 - i] = --s[i];
                for (++i; m - 1 - i >= i; ++i) {
                    s[i] = s[m - 1 - i] = '9';
                }
                return s;
            }
        }
        if (m == 1) {
            return "0";
        }
        return string(m - 1, '9');

    }

    string make2(const string &n) {
        const int m = n.length();
        string s = n;
        for (int i = 0, j = m - 1; i <= j; s[j--] = s[i++])
        ;
        if (s > n) {
            return s;
        }
        for (int i = (m - 1) >> 1; i >= 0; --i) {
            if (s[i] == '9') {
                continue;
            }
            s[m - 1 - i] = ++s[i];
            for (++i; m - 1 - i >= i; ++i) {
                s[i] = s[m - 1 - i] = '0';
            }
            return s;
        }
        s = string(m + 1, '0');
        s[0] = s.back() = '1';
        return s;
    }
public:
    string nearestPalindromic(string n) {
        const string s1 = make1(n), s2 = make2(n);
        const long long p = stoll(n);
        return  stoll(s2) - p < p - stoll(s1) ? s2 : s1;
        
        
    }
};