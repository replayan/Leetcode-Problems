class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), max_product = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                max_product = max(max_product, (nums[j] - 1) * (nums[i] - 1));
            }
        }
        return max_product;
    }
};
