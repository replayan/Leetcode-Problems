class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> ind(n);
        for (int i = 0; i < n; ++i) {
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(), [&](const int &x, const int &y) 
             {return endTime[x] < endTime[y];});
        map<int, int> dp;
        dp[0] = 0;
        for (int i : ind) {
            auto t = dp.upper_bound(startTime[i]);
            int may = (--t)->second + profit[i];
            if (dp.rbegin()->second < may) {
                dp[endTime[i]] = may;
            }
        }
        return dp.rbegin()->second;
    }
};