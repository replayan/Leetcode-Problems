class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0, j = n - 1, count = 0;
        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                count = (count + power(2, j - i, MOD)) % MOD;
                i++;
            } else {
                j--;
            }
        }
        return count;
    }
private:
    int power(int x, int n, int MOD) {
        int ans = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                ans = static_cast<long long>(ans) * x % MOD;
            }
            x = static_cast<long long>(x) * x % MOD;
            n /= 2;
        }
        return ans;
    }
};