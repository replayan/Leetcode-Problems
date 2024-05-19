class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        # XOR is not a blackbox, n ^ k ^ k = n
        # thus we can (and must) xor any 2 nodes at a time
        # greedy, sort by xor delta
        delta = [(n ^ k) - n for n in nums]
        delta.sort(reverse=True)
        res = sum(nums)
        for i in range(0, len(nums), 2):
            if i == len(nums) - 1:
                break
            path_delta = delta[i] + delta[i + 1]
            if path_delta <= 0:
                break
            res += path_delta
        return res
