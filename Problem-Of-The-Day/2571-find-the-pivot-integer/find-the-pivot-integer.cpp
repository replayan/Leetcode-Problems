class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        int leftSum = 0;
        int rightSum = 0;

        for (int i = 1; i <= n; i++) {
            sum += i;
        }

        // Iterate through digits to find the pivot integer
        for (int i = 1; i <= n; i++) {
            leftSum += i - 1;
            rightSum = sum - leftSum - i;

            if (leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};