class Solution {
private:
    int rev(int x) {
        int reversed = 0;
        while (x != 0) {
            int digit = x % 10;
            if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) return 0;
            reversed = reversed * 10 + digit;
            x /= 10;
        }
        return reversed;
    }

public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> frequency;
        long long nicePairs = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            int diff = nums[i] - rev(nums[i]);
            nicePairs += frequency[diff];
            nicePairs %= MOD;
            frequency[diff]++;
        }
        return nicePairs;
    }
};
