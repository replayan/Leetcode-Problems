class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0

        maxEndingHere = maxSoFar = nums[0]

        for num in nums[1:]:
            maxEndingHere = max(num, maxEndingHere + num)
            maxSoFar = max(maxSoFar, maxEndingHere)

        return maxSoFar
