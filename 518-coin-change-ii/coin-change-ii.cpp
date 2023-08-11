class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1; 
        
        for (int coin : coins) {
            for (int currAmount = coin; currAmount <= amount; ++currAmount) {
                dp[currAmount] += dp[currAmount - coin];
            }
        }
        return dp[amount];
    }
};
