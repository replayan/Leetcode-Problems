class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        cache = {}

        def count(i, k, prev, prev_count):
            if (i, k, prev, prev_count) in cache:
                return cache[(i, k, prev, prev_count)]
            if k < 0:
                return float("inf")
            if i == len(s):
                return 0
            if s[i] == prev:
                incrm = 1 if prev_count in [1, 9, 99] else 0
                res = incrm + count(i + 1, k, prev, prev_count + 1)
            else:
                res = min(
                    count(i + 1, k - 1, prev, prev_count),
                    1 + count(i + 1, k, s[i], 1),
                )
            cache[(i, k, prev, prev_count)] = res
            return res

        return count(0, k, "", 0)
