class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1, right = *max_element(candies.begin(), candies.end());
        while (left <= right) {
            const int mid = (left + right) >> 1;
            long long temp = k;
            for (int i = 0; i < candies.size() && temp > 0; ++i) {
                temp -= candies[i] / mid;
            }
            if (temp <= 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
        
    }
};