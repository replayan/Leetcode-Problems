class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int s = 0;
        for (int x : nums) {
            s = (s + x) % p;
        }
        if (s == 0)
            return 0;
        const int n = nums.size();
        int r = n;
        unordered_map<int, int> have = {{0, 0}};
        for (int i = 1, t = 0; i <= n; ++i) {
            t = (t + nums[i - 1]) % p;
            const auto it = have.find((t - s + p) % p);
            if (it != have.end()) {
                r = min(r, i - it->second);
            }
            have[t] = i;
        }
        return r == n ? (-1) : r;
    }
};