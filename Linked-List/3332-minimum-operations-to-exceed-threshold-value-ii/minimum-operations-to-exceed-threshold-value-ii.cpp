class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> s(nums.begin(), nums.end());
        int r = 0;
        for (; *s.begin() < k; ++r) {
            const long long x = *s.begin();
            s.erase(s.begin());
            const long long y = *s.begin();
            s.erase(s.begin());
            s.insert(x + x + y);
        }
        return r;
    }
};