class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (num < k) return -1;
            if (num > k) seen.insert(num);
        }
        return seen.size();
    }
};
