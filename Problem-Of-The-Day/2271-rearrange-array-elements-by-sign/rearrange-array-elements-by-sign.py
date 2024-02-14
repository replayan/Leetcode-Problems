class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        neg, pos, i = [], [], 0
        for n in nums:
            if n > 0:
                pos.append(n)
            else:
                neg.append(n)
        while 2 * i < len(nums):
            nums[2 * i] = pos[i]
            nums[2 * i + 1] = neg[i]
            i += 1
        return nums
