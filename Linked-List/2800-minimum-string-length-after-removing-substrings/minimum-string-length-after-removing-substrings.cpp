class Solution {
public:
    int minLength(string s) {
        string p;
        for (char c : s) {
            if ((c == 'B' && !p.empty() && p.back() == 'A') ||
                (c == 'D' && !p.empty() && p.back() == 'C')) {
                p.pop_back();
            } else {
                p.push_back(c);
            }
        }
        return p.length();
    }
};