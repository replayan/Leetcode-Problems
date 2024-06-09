class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = size(nums);
        int count = 0, sum = 0;
        vector<int> freq(k, 0); 
        freq[0] = 1; 

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int remainder = sum % k;
            if (remainder < 0) {
                remainder += k;
            }
            count += freq[remainder];
            freq[remainder]++;
        }
        return count;
    }
};
