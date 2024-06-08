class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> remainderMap;
        int sum = 0;
        remainderMap[0] = -1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int remainder = k == 0 ? sum : sum % k;
            if (remainderMap.count(remainder)) {
                if (i - remainderMap[remainder] > 1) {
                    return true;
                }
            } else {
                remainderMap[remainder] = i;
            }
        }
        return false;
    }
};
