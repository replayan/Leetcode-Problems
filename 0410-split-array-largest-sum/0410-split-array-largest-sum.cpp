class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long left = *max_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(), nums.end(), 0LL);

        while (left < right) {
            long long mid = left + (right - left) / 2;
            int subArrays = 1;
            long long currentSum = 0;

            for (int num : nums) {
                if (currentSum + num > mid) {
                    currentSum = 0;
                    ++subArrays;
                }
                currentSum += num;
            }
            if (subArrays > k) {
                left = mid + 1; 
            } else {
                right = mid; 
            }
        }
        return left; 
    }
};
