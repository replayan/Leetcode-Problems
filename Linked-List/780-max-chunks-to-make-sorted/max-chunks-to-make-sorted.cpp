class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> mini(n), maxi(n);
        for (int i = 0; i < n; ++i) {
            maxi[i] = (i ? max(maxi[i - 1], arr[i]) : arr[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            mini[i] = (i != n - 1 ? min(mini[i + 1], arr[i]) : arr[i]);
        }
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {

                if (maxi[j] <= mini[j + 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};