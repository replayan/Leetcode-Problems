class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // Find the maximum element in the 'nums' array
        int max_e = *max_element(nums.begin(), end(nums));
        
        int count = 0; // Counter for occurrences of 'max_e' in the current window
        int left = 0, right = 0; // Pointers for sliding window
        long long result = 0; // Final result (number of subarrays)
        
        // Loop through the array using sliding window technique
        while (right < nums.size()) {
            // Step 1: Check if the current element is equal to 'max_e'
            if (nums[right] == max_e) {
                count++; // Increment count if it is
            }
            
            // Step 2: Shrink the window if count is greater than or equal to 'k'
            while (count >= k) {
                // Add the number of valid subarrays ending at position 'right'
                result += nums.size() - right;
                
                // Move the left pointer (left) and update count accordingly
                if (nums[left] == max_e) {
                    count--; // Decrement count if element at 'left' is 'max_e'
                }
                left++; // Move left pointer to the right
            }
            right++; // Move right pointer to the right
        }
        return result;
    }
};
