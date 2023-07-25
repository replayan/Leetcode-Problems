class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid - 1] < nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};