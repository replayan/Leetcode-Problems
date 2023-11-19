class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int operations = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
            if (nums[i] > nums[i + 1])
                operations += (i + 1);
        return operations;
    }
};
