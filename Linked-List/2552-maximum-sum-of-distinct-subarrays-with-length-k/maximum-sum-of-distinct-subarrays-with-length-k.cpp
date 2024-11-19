class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<int> p;
        multiset<int> s;
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            s.insert(nums[i]);
            p.insert(nums[i]);
            sum += nums[i];
        }
        long long r = 0;
        if (p.size() == k) {
            r = sum;
        }
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i];
            s.insert(nums[i]);
            p.insert(nums[i]);
            sum -= nums[i - k];
            s.erase(s.find(nums[i - k]));
            if (s.find(nums[i - k]) == s.end()) {
                p.erase(nums[i - k]);
            }
            if (p.size() == k) {
                r = max(r, sum);
            }
        }
        return r;
    }
};