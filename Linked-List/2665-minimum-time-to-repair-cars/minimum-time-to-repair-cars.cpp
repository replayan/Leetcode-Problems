class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0, right = cars * 1LL * cars *
                                    *max_element(ranks.begin(), ranks.end());
        while (left <= right) {
            const long long mid = (left + right) >> 1;
            int temp = cars;
            for (int r : ranks) {
                temp -= (int)sqrt(mid / r);
                if (temp <= 0) {
                    break;
                }
            }

            if (temp <= 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right + 1;
    }
};