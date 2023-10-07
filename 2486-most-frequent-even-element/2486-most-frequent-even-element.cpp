class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> countMap;
        int mostFrequent = -1;
        int maxCount = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                countMap[num]++;
                if (countMap[num] > maxCount || (countMap[num] == maxCount && num < mostFrequent)) {
                    mostFrequent = num;
                    maxCount = countMap[num];
                }
            }
        }
        return mostFrequent;
    }
};
