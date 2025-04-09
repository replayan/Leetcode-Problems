class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Step 1: Check if any element is less than k
        for (int num : nums) {
            if (num < k) {
                return -1;
            }
        }
        
        int operations = 0;
        
        // Step 2: Simulate operations until all equal k
        while (true) {
            // Check if all elements are k
            bool all_k = true;
            for (int num : nums) {
                if (num != k) {
                    all_k = false;
                    break;
                }
            }
            if (all_k) {
                return operations;
            }
            
            // Find the maximum
            int max_val = nums[0];
            for (int num : nums) {
                if (num > max_val) {
                    max_val = num;
                }
            }
            
            // If max is k or less, we should be done, but since we checked above, max > k
            // Find the second largest to set h (naively)
            int second_max = k; // Minimum h can be k
            for (int num : nums) {
                if (num > second_max && num < max_val) {
                    second_max = num;
                }
            }
            
            int h = second_max;
            // Verify h is valid: all elements > h must be max_val
            for (int num : nums) {
                if (num > h && num != max_val) {
                    // This shouldn't happen if we picked h correctly, but for naivety, adjust
                    h = max_val - 1; // Fallback to just below max
                    break;
                }
            }
            
            // Apply operation
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > h) {
                    nums[i] = h;
                }
            }
            operations++;
        }
        
        return operations;
    }
};