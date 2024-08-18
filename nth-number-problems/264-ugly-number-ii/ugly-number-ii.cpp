class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> f(n);
        for (int i = f[0] = 1, ind2 = 0, ind3 = 0, ind5 = 0; i < n; ++i) {
            f[i] = f[ind2] << 1;
            f[i] = min(f[i], f[ind3] * 3);
            f[i] = min(f[i], f[ind5] * 5);
            if (f[i] == f[ind2] * 2) ++ind2;
            if (f[i] == f[ind3] * 3) ++ind3;
            if (f[i] == f[ind5] * 5) ++ind5;
        }
        return f[n - 1];
        
    }
};