class Solution {
    public int maximumCount(int[] nums) {
        int pos = (int) Arrays.stream(nums).filter(x -> x > 0).count();
        int neg = (int) Arrays.stream(nums).filter(x -> x < 0).count();

        return Math.max(pos, neg);
    }
}
