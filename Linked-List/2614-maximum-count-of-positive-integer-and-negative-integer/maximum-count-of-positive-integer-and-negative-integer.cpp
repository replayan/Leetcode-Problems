class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negative_count = 0, positive_count = 0;
        int left = 0, right = nums.size() - 1;
        
        // Find rightmost negative
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                negative_count = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        left = 0, right = nums.size() - 1;
        
        // Find leftmost positive
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                positive_count = nums.size() - mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return max(positive_count, negative_count);
    }
};
