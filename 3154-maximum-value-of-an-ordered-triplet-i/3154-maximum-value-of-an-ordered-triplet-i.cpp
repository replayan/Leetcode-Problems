class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxTripletValue = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    long long tripletValue = 1LL * (nums[i] - nums[j]) * nums[k];
                    maxTripletValue = max(maxTripletValue, tripletValue);
                }
            }
        }
        return maxTripletValue;
    }
};
