class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int freq_i = 0;
                int freq_j = 0;

                // Count the frequency of nums[i]
                for (int k = 0; k < n; ++k) {
                    if (nums[k] == nums[i]) {
                        freq_i++;
                    }
                }

                // Count the frequency of nums[j]
                for (int k = 0; k < n; ++k) {
                    if (nums[k] == nums[j]) {
                        freq_j++;
                    }
                }

                // Compare frequencies and swap if necessary
                if (freq_i > freq_j || (freq_i == freq_j && nums[i] < nums[j])) {
                    swap(nums[i], nums[j]);
                }
            }
        }
        return nums;
    }
};
