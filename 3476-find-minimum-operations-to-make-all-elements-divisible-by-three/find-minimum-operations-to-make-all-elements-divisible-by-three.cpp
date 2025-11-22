class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int total_ops = 0;

        for (int i = 0; i < size(nums); ++i) {
            if ((nums[i] % 3) != 0) {
                total_ops += 1;
            }
        }
        return total_ops;
    }
};