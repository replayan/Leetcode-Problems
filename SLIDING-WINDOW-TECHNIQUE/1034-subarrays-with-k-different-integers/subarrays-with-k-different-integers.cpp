class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // To keep track of counts of distinct elements
        unordered_map<int, int> count;
        int res = 0; // The result variable
        int left_near = 0; // The left pointer for the "near" end of the window
        int left_far = 0; // The left pointer for the "far" end of the window
        
        // Loop through the array using the right pointer
        for (int right = 0; right < nums.size(); right++) {
            // Increase the count of the current element in the map
            count[nums[right]] += 1;
            
            // While the number of distinct elements exceeds 'k'
            while (count.size() > k) {
                // Decrease the count of the element at the "near" end of the window
                count[nums[left_near]] -= 1;
                
                // If the count becomes zero, remove the element from the map
                if (count[nums[left_near]] == 0) {
                    count.erase(nums[left_near]);
                }
                
                // Move the "near" pointer to the right
                left_near += 1;
                
                // Set the "far" pointer equal to the "near" pointer
                left_far = left_near;
            }
            
            // While there are duplicate elements at the "near" end of the window
            while (count[nums[left_near]] > 1) {
                // Decrease the count of the element at the "near" end of the window
                count[nums[left_near]] -= 1;
                
                // Move the "near" pointer to the right
                left_near += 1;
            }
            
            // If the number of distinct elements in the window is 'k'
            if (count.size() == k) {
                // Update the result by adding the number of subarrays that satisfy the condition
                res += left_near - left_far + 1;
            }
        }
        return res;
    }
};
