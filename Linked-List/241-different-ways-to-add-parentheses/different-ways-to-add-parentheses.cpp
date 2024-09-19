class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> num;
        vector<char> op;
         for (int i = 0; i < expression.size();) {
             if (isdigit(expression[i])) {
                 int x = 0;
                 for (; i < expression.length() && isdigit(expression[i]); x = x * 10 + expression[i++] - '0')
                 ;
                 num.push_back(x);
             } else {
                 op.push_back(expression[i++]);
             }
         }
         const int n = num.size();
         vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
         for (int d = 0; d < n; ++d) {
             for (int i = 0; i + d < n; ++i) {
                 if (d == 0) {
                     dp[i][i].push_back(num[i]);
                     continue;
                 }
                 for (int j = i + d, k = i; k < j; ++k) {
                     for (int x : dp[i][k]) {
                         for (int y : dp[k + 1][j]) {
                             switch(op[k]) {
                                 case '+':
                                 dp[i][j].push_back(x + y);
                                 break;
                                 case '-':
                                 dp[i][j].push_back(x - y);
                                 break;
                                 case '*':
                                 dp[i][j].push_back(x * y);
                                 break;
                             }
                         }
                     }
                 }
             }
         }
         return dp[0][n - 1];
    }
};