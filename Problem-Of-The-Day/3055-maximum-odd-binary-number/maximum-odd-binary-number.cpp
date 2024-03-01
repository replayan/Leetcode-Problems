class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        const int n = s.length();
        int r = 0;
        for (char c : s) {
            r += c - '0';
        }
        return string(r - 1, '1') + string(n - r, '0') + "1";
        
    }
};