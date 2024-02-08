class Solution {
public:
    int numSquares(int n) {
        // Create a vector 'dp' to store the minimum number of perfect squares needed to sum up to each number from 0 to 'n'.
        vector<int> dp(n + 1, INT_MAX);
        // Initialize 'dp[0]' to 0 because it takes zero perfect squares to sum up to 0.
        dp[0] = 0;
        // Loop through all numbers from 1 to 'n'.
        for (int i = 1; i <= n; ++i) {
            // Loop through all perfect squares 'j * j' such that 'j * j' is less than or equal to 'i'.
            for (int j = 1; j * j <= i; ++j) {
                // Update 'dp[i]' by taking the minimum of its current value and 'dp[i - j * j] + 1'.
                // 'dp[i - j * j]' represents the minimum number of perfect squares needed to sum up to 'i - j * j'.
                // Adding 1 represents using one more perfect square (j * j).
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        // Return 'dp[n]' which contains the minimum number of perfect squares needed to sum up to 'n'.
        return dp[n];
    }
};
