class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        else
            return (1 << 30) % n == 0;
    }
}