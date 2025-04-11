class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        assert(1 <= low);
        assert(low <= high);
        assert(high <= 10000);
        int r = 0;
        for (int i = low; i <= high; ++i) {
            const string s = to_string(i);
            if (s.length() & 1) continue;
            int x = 0;
            const int m = s.length() >> 1;
            for (int i = 0; i < s.length(); ++i) {
                x += i < m ? (s[i] - '0') : -(s[i] - '0');
            }
            r += x == 0;
        }
        return r;
        
    }
};