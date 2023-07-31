class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size()-1;
        if (n == 0) {
            return false;
        }
        
        unordered_map<int, int> freqMap;
        int countN = 0;
        
        for (int num : nums) {
            freqMap[num]++;
            if (num == n) {
                countN++;
            }
        }
        
        if (countN != 2) {
            return false;
        }
        
        for (int i = 1; i <= n - 1; i++) {
            if (freqMap[i] != 1) {
                return false;
            }
        }
        return true;
    }
};
