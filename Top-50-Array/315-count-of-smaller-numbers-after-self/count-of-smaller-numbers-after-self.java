class Solution {
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        List<Integer> counts = new ArrayList<>();
        int[] smallerCounts = new int[n];
        int[] indexes = new int[n];

        for (int i = 0; i < n; i++) {
            indexes[i] = i;
        }

        int[] tempIndexes = new int[n];
        int[] tempSmallerCounts = new int[n];
        for (int size = 1; size < n; size *= 2) {
            for (int low = 0; low < n - size; low += 2 * size) {
                int mid = low + size - 1;
                int high = Math.min(low + 2 * size - 1, n - 1);
                int leftIndex = low;
                int rightIndex = mid + 1;
                int mergeIndex = 0;
                int rightCount = 0;

                while (leftIndex <= mid && rightIndex <= high) {
                    if (nums[indexes[rightIndex]] < nums[indexes[leftIndex]]) {
                        rightCount++;
                        tempIndexes[mergeIndex] = indexes[rightIndex];
                        tempSmallerCounts[mergeIndex] = smallerCounts[indexes[rightIndex]];
                        mergeIndex++;
                        rightIndex++;
                    } else {
                        smallerCounts[indexes[leftIndex]] += rightCount;
                        tempIndexes[mergeIndex] = indexes[leftIndex];
                        tempSmallerCounts[mergeIndex] = smallerCounts[indexes[leftIndex]];
                        mergeIndex++;
                        leftIndex++;
                    }
                }

                while (leftIndex <= mid) {
                    smallerCounts[indexes[leftIndex]] += rightCount;
                    tempIndexes[mergeIndex] = indexes[leftIndex];
                    tempSmallerCounts[mergeIndex] = smallerCounts[indexes[leftIndex]];
                    mergeIndex++;
                    leftIndex++;
                }

                while (rightIndex <= high) {
                    tempIndexes[mergeIndex] = indexes[rightIndex];
                    tempSmallerCounts[mergeIndex] = smallerCounts[indexes[rightIndex]];
                    mergeIndex++;
                    rightIndex++;
                }
                // Copy the merged results
                for (int i = 0; i < mergeIndex; i++) {
                    indexes[low + i] = tempIndexes[i];
                    smallerCounts[indexes[low + i]] = tempSmallerCounts[i];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            counts.add(smallerCounts[i]);
        }
        return counts;
    }
}
