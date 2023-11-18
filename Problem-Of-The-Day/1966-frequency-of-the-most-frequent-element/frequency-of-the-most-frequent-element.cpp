class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long int n = nums.size(), sum = 0, left = 0, maxFreq = 0;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (static_cast<long long>(nums[right]) * (right - left + 1) > sum + k) {
                sum -= nums[left++];
            }
            maxFreq = max(maxFreq, right - left + 1);
        }
        return maxFreq;
    }
};
