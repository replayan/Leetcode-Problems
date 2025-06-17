class Solution {
    const int M = 1000000007;
    int mul(long long x, long long y) { return x * y % M; }

    int pow(int x, int y) {
        int r = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                r = mul(r, x);
            }
            x = mul(x, x);
        }
        return r;
    }

    int C(int m, int n) {
        int r = 1;
        for (int i = 1; i <= n; ++i) {
            r = mul(r, m - i + 1);
            r = mul(r, pow(i, M - 2));
        }
        return r;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        if (m == 1) {
            return k == n - 1;
        }
        return mul(mul(C(n - 1, k), m), pow(m - 1, n - 1 - k));
    }
};