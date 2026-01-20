class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int p : nums) {
            // x | (x + 1) is always odd → evens impossible
            if ((p & 1) == 0) {
                ans.push_back(-1);
                continue;
            }
            
            // Count trailing 1s
            int t = 0;
            int temp = p;
            while (temp & 1) {
                t++;
                temp >>= 1;
            }
            
            // Minimal x
            int x = p - (1 << (t - 1));
            ans.push_back(x);
        }
        
        return ans;
    }
};
