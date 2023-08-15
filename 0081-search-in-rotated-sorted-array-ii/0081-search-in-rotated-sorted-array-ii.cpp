class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) { 
            int mid = left + (right - left) / 2; 
            if (nums[mid] == target) {
                return true;
            }
            
            // case of duplicate elements by moving the left pointer.
            while (left < mid && nums[left] == nums[mid]) {
                ++left;
            }
            
            if (nums[left] <= nums[mid]) { // Checking if the left half is sorted.
                if (nums[left] <= target && nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }       
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
