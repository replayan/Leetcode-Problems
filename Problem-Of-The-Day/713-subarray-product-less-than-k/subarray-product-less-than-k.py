class Solution:
    def numSubarrayProductLessThanK(self, nums, k):
        # Using the same sliding window template
        if k <= 1:
            return 0
        n = len(nums)
        count = 0
        i, j = 0, 0
        product = 1
        while j < n:
            product *= nums[j]
            while product >= k:
                product /= nums[i]
                i += 1
            count += (j - i) + 1
            j += 1
        return count
