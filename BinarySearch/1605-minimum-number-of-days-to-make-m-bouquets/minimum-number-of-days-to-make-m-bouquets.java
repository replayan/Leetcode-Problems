class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int inf = 1000000000;
        int n = bloomDay.length;
        
        // Check if there are enough flowers to make m bouquets
        if ((long) m * k > n) return -1;

        int left = 0, right = inf;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Midpoint to check
            int bouquets = 0, flowers = 0;

            for (int i = 0; i < n; ++i) {
                if (bloomDay[i] <= mid) {
                    if (++flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }

            if (bouquets >= m) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
}
