class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> distinctGreaterThanK;
        for (int num : nums) {
            if (num < k) {
                return -1;
            }
            if (num > k) {
                distinctGreaterThanK.insert(num);
            }
        }
        return distinctGreaterThanK.size();
    }
};