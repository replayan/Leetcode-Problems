class Solution {
public:
    int tribonacci(int n) {
        vector<int> tribo = {0, 1, 1};
        for (int i = 3; i <= n; ++i) {
            tribo.push_back(tribo[i - 1] + tribo[i - 2] + tribo[i - 3]);
        }
        return tribo[n];
    }
};