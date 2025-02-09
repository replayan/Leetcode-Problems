class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> have;
        long long r = 0;
        for (int i = 0; i < nums.size(); ++i) {
            r += i - have[i - nums[i]]++;
        }
        return r;
    }
};