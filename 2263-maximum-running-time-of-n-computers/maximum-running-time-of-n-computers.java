public class Solution {
    public long maxRunTime(int n, int[] batteries) {
        Arrays.sort(batteries);
        int m = batteries.length;
        int d = m - n;
        long s = 0;
        for (int i = 0; i < d; ++i) {
            s += batteries[i];
        }
        long r = batteries[d];
        for (int i = d + 1; s > 0 && i < m; ++i) {
            long need = (long) (batteries[i] - batteries[i - 1]) * (i - d);
            if (need > s) {
                return r + s / (i - d);
            }
            s -= need;
            r = batteries[i];
        }
        return r + s / n;
    }
}
