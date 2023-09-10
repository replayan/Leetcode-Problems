// Formula : (2n)! / (n! * (n + 1)!)

class Solution {
public:
    int countOrders(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 1;
        for (int i = 2; i <= 2 * n; i += 2) {
            ans = (ans * i * (i - 1) / 2) % MOD;
        }
        return static_cast<int>(ans);
    }
};
