class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> have;
        for (int p = 0, i = 0; i < nums.size(); ++i) {
            const int temp = (p + nums[i]) % k;
            if (have.count(temp)) {
                return true;
            }
            have.insert(p);
            p = temp;
        }
        return false;
        
    }
};