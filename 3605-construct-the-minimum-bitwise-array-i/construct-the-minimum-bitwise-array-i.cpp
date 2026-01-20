class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int p : nums) {
            int found = -1;
            
            for (int x = 0; x < p; x++) {
                if ( (x | (x + 1)) == p ) {
                    found = x;
                    break;  // minimal by construction
                }
            }
            
            ans.push_back(found);
        }
        
        return ans;
    }
};
