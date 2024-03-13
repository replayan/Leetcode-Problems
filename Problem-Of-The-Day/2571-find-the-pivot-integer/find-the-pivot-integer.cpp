// simple o(n^2) solution
class Solution {
public:
    int pivotInteger(int n) {
        /*
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
        */
        // o(n) solution
        int lSum = 1;
        int rSum = n;
        int i = 1, j = n;
        while (i < j) {
            if (lSum < rSum) {
                ++i;
                lSum += i;
            } else {
                --j;
                rSum += j;
            }
        }
        return lSum == rSum ? i : -1;
    }
};