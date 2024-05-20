class Solution {
    int dfs(const vector<int> &v, int now, int s) {
        if (now == v.size()) {
            return s;
        }
        return dfs(v, now + 1, s) + dfs(v, now + 1, s ^ v[now]);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
        
    }
};