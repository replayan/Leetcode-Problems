class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        const int t = m ^ n;
        int i;
        for (i = 31; i && (((t >> i) & 1) == 0); --i)
            ;
        return (m & n) >> i << i;
    }
};