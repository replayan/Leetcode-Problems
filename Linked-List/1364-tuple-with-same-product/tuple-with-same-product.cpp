class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> have;
        int r = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                r += have[nums[i] * nums[j]]++;
            }
        }
        return r << 3;
    }
};