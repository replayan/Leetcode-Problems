class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /* Time Limit Exceeded, TC => O(N^3)
        int n = nums.size(), count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                long long product = 1;
                for (int l = i; l < j; ++l) {
                    if (product > k / nums[l]) { // to avoid overflow
                        product = k + 1;
                        break;
                    }
                    product *= nums[l];
                }
                if (product < k) {
                    count++;
                }
            }
        }
        return count;
        */

        // Using same sliding window template
        if (k <= 1) {
            return 0;
        }
        int n = nums.size();
        int count = 0;
        int i = 0, j = 0;
        int product = 1;
        while (j < n) {
            product *= nums[j];
            while (product >= k) {
                product /= nums[i];
                ++i;
            }
            count += (j - i) + 1;
            ++j;
        }
        return count;
    }
};