class Solution {
    int count(long long n, long long pre) {
        int r = 0;
        for (long long a = pre, b = pre; a <= n; a *= 10, b = b * 10 + 9) {
            r += min(n, b) - a + 1;
        }
        return r;
    }
    int dfs(int n, int k, int pre = 0) {
        if (k == 0) {
            return pre;
        }
        for (int i = pre ? 0 : 1; i <= 9; ++i) {

            const int m = count(n, pre * 10 + i);
            if (k <= m) {
                return dfs(n, k - 1, pre * 10 + i);
            } else {
                k -= m;
            }
        }
        return -1;
    }

public:
    int findKthNumber(int n, int k) { return dfs(n, k); }
};