class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) { 
            int mid = left + (right - left) / 2; 
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) { // Check if the left half is sorted.
                if (nums[left] <= target && nums[mid] > target) { // If target is within the sorted left half.
                    right = mid - 1; // Update the right pointer to narrow the search to the left half.
                } else {
                    left = mid + 1; // Update the left pointer to narrow the search to the right half.
                }       
            } else { // If the right half is sorted.
                if (nums[mid] < target && target <= nums[right]) { // If target is within the sorted right half.
                    left = mid + 1; // Update the left pointer to narrow the search to the right half.
                } else {
                    right = mid - 1; // Update the right pointer to narrow the search to the left half.
                }
            }
        }
        return -1;
    }
};
