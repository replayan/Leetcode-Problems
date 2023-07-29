// o(N) approach counting,prefix sum

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);
        vector<int> result;

        for (int num : nums) count[num]++;
        
        for (int i = 1; i <= 100; i++) count[i] += count[i - 1];
        
        for (int num : nums) result.push_back(num == 0 ? 0 : count[num - 1]);

        return result;
    }
};
