class Solution {
    void dfs(const vector<int>& nums, int ind, int v, int& best, int& num) {
        if (ind >= nums.size()) {
            if (v > best) {
                best = v;
                num = 1;
            } else if (v == best) {
                ++num;
            }
            return;
        }
        dfs(nums, ind + 1, v, best, num);
        dfs(nums, ind + 1, v | nums[ind], best, num);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int num = 0, best = 0;
        dfs(nums, 0, 0, best, num);
        return num;
    }
};