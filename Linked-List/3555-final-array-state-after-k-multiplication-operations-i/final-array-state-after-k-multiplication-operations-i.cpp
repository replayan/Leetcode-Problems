class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (; k; --k) {
            int m = INT_MAX;
            for (int x : nums) {
                m = min(m, x);
            }
            for (int& x : nums) {
                if (x == m) {
                    x *= multiplier;
                    break;
                }
            }
        }
        return nums;
    }
};