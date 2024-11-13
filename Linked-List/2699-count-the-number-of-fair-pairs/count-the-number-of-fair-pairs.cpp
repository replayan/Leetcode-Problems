class Solution {
    long long count(const vector<int>& v, int x) {
        long long r = 0;
        for (int i = 0, j = v.size() - 1; i < j;) {
            if (v[i] + v[j] > x) {
                --j;
            } else {
                r += j - i++;
            }
        }
        return r;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return count(nums, upper) - count(nums, lower - 1);
    }
};