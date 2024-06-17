class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = static_cast<long long>(sqrt(c));
        while (left <= right) {
            long long sum = left * left + right * right;
            if (c == sum) {
                return true;
            } else if (sum < c) {
                left += 1;
            } else {
                right -= 1;
            }
        }
        return false;
    }
};