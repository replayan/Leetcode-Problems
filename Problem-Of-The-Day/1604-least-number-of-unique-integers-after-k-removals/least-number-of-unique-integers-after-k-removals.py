class Solution:
    def findLeastNumOfUniqueInts(self, arr, k):
        count = Counter(arr)
        counts_sorted = sorted(count.values())
        num_unique = len(counts_sorted)
        for count_value in counts_sorted:
            if count_value <= k:
                num_unique -= 1
                k -= count_value
            else:
                break
        return num_unique
