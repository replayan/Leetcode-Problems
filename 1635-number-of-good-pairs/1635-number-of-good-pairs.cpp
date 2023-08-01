// Hashmap Solution

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> elementFreq;
        int goodPairCount = 0;
        for(int i : nums){
            goodPairCount += elementFreq[i];
            elementFreq[i]++;
        }
        return goodPairCount;
    }
};