// simple o(n^2) solution
class Solution {
public:
    int pivotInteger(int n) {
        for (int p = 1; p <= n; ++p) {
            int lSum = 0;
            int rSum = 0;
            for (int i = 1; i <= p; ++i) {
                lSum += i;
            }
            for (int i = p; i <= n; ++i) {
                rSum += i;
            }
            if (lSum == rSum) {
                return p;
            }
        }
        return -1;
    }
};