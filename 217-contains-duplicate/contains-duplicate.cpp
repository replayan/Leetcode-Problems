class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> seen;
        for(int i:nums){
            seen[i]++;
            if(seen[i]>1){
                return true;
            }
        }
        return false;
    }
};