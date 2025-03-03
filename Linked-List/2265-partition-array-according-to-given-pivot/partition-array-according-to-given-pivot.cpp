class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        const int n = nums.size();
        vector<int> r(n, pivot);
        for (int i = 0, j = 0; j < n; ++j) {
            if (nums[j] < pivot) {
                r[i++] = nums[j];
            }
        }
        for (int i = n - 1, j = n - 1; j >= 0; --j) {
            if (nums[j] > pivot) {
                r[i--] = nums[j];
            }
        }
        return r;
    }
};