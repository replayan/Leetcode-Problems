class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the dominant element (must appear > n/2 times)
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int dominant = -1;
        for (auto& [num, count] : freq) {
            if (count > n/2) {
                dominant = num;
                break;
            }
        }
        
        // If no dominant element exists, return -1
        if (dominant == -1) return -1;
        
        // Step 2: Find the minimum split point
        int leftCount = 0;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == dominant) {
                leftCount++;
            }
            
            int leftSize = i + 1;
            int rightSize = n - leftSize;
            
            // Check if dominant in both parts
            if (leftCount > leftSize/2 && 
                (freq[dominant] - leftCount) > rightSize/2) {
                return i;
            }
        }
        
        return -1;
    }
};
