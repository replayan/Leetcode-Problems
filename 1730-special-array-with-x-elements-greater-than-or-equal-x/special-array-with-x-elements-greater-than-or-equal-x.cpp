class Solution {
public:
    int specialArray(vector<int>& nums) {
        // TC -> O(n^2)
        int n = nums.size();
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            for (int num : nums) {
                if (num >= i)
                    count += 1;
            }
            if (count == i)
                return i;
        }
        return -1;
    }
};