class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_e = *max_element(nums.begin(), end(nums));
        int count = 0;
        int i = 0, j = 0;
        long long result = 0;
        while (j < nums.size()) {
            if (nums[j] == max_e) {
                count++;
            }
            while (count >= k) {
                result += nums.size() - j;
                if (nums[i] == max_e) {
                    count--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};