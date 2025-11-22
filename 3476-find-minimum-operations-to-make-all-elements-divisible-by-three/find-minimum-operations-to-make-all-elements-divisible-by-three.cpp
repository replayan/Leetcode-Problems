class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // int min_ops = 0;

        // for (int i = 0; i < size(nums); ++i) {
        //     if ((nums[i] % 3) != 0) {
        //         min_ops += 1;
        //     }
        // }
        // return min_ops;

        int minOps = 0;
        for (int i : nums) if (i % 3) minOps += 1; return minOps;
    }
};