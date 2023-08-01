class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> frequency;
        int goodPairs = 0;

        for (int num : nums) {
            goodPairs += frequency[num];
            frequency[num]++;
        }
        return goodPairs;
    }
};
