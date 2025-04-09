class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> distinctGreaterThanK;
        for (int num : nums) {
            if (num < k) {
                return -1; // Impossible if any element is less than k
            }
            if (num > k) {
                distinctGreaterThanK.insert(num); // Collect distinct values > k
            }
        }
        return distinctGreaterThanK.size(); // Number of operations
    }
};