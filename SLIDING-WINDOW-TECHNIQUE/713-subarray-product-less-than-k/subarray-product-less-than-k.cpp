class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // If k is less than or equal to 1, no subarray product can be less than k
        if (k <= 1) {
            return 0;
        }
        
        int n = nums.size(); 
        int count = 0; // the count variable to store the number of subarrays
        int i = 0, j = 0; // pointers i and j for the sliding window
        int product = 1; // the product variable to store the product of elements in the current window
        
        // Loop through the array using the right pointer j
        while (j < n) {
            product *= nums[j]; // Multiply the current product with the element at the right pointer
            
            // While the product is greater than or equal to k
            while (product >= k) {
                product /= nums[i]; // Divide the product by the element at the left pointer
                ++i; // Move the left pointer i to the right
            }
            
            // Update the count by adding the number of subarrays in the current window
            // The number of subarrays is equal to (j - i) + 1
            count += (j - i) + 1;
            
            ++j; // Move the right pointer j to the right to expand the window
        }
        
        return count; // Return the total count of subarrays
    }
};
