class Solution {
    const int M = 1000000007;
    void add(int &x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
    }
public:
    int countHomogenous(string s) {
        int r = 0;
        for (int last = ' ', i = 0, len = 0; i < s.length(); ++i) {
            if (last != s[i]) {
                len = 0;
                last = s[i];
            }
            add(r, ++len);
            
        }
        return r;
        
    }
};