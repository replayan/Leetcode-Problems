class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.rbegin(), happiness.rend()); // Sort in non-increasing order

        long long maxSum = 0;
        for (int i = 0; i < k; ++i) {
            maxSum += max(happiness[i] - i, 0); // Adjust for happiness decrement
        }

        return maxSum;
    }
};
