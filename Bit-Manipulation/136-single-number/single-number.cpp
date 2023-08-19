class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Brute force approach - O(n^2) time complexity
        /*
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            bool duplicate = false;
            for (int j = 0; j < n; j++) {
                if (i != j && nums[j] == nums[i]) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) {
                return nums[i];
            }
        }
        throw invalid_argument("No single number found.");
        */
        
        // Better approach - Sorting (O(nLog(n))) - O(nLog(n)) time complexity
        /*
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) {
            if (i + 1 >= nums.size() || nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        throw invalid_argument("No single number found.");
        */
        
        // Much better approach - Hash map (O(n)) - O(n) time complexity
        /*
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (const auto& pair : freq) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        throw invalid_argument("No single number found.");
        */
        
        // Best approach - Bit manipulation (O(n)) - O(n) time complexity
        
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
        
        
        // Binary search approach - O(log(n)) time complexity
        // int left = 0, right = nums.size() - 1;
        // while (left < right) {
        //     int mid = left + (right - left) / 2;
        //     if (mid % 2 == 1) {
        //         mid--; // mid is even
        //     }
        //     if (nums[mid] != nums[mid + 1]) {
        //         right = mid; 
        //     } else {
        //         left = mid + 2; 
        //     }
        // }
        // return nums[left];
    }
};
