class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> have;
        for (int x : nums) {
            ++have[x];
        }
        int r = 1;
        while (!have.empty()) {
            int x = have.begin()->first;
            for (;have.count(x - k); x -=k)
            ;
            vector<int> dp = {1, 1 << have[x], 0};
            have.erase(x);
            int ind = 1;
            for (x += k; have.count(x); x += k) {
                ++ind;
                dp[ind % 3] = dp[(ind - 1) % 3] + 
                (dp[(ind - 2) % 3] << have[x]) - dp[(ind - 2) % 3];
                have.erase(x);
            }
            r *= dp[ind % 3];
        }
        
        return r - 1;
    }
};