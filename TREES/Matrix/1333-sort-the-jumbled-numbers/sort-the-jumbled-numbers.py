class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        pair = []
        for i, n in enumerate(nums):
            n = str(n)
            mapped_n = 0
            for c in n:
                mapped_n *= 10
                mapped_n += mapping[int(c)]
            pair.append((mapped_n, i))
        pair.sort()
        return [nums[p[1]] for p in pair]
