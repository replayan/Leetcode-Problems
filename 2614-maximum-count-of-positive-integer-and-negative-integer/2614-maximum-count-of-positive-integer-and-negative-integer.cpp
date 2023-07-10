class Solution {
public:
    int maximumCount(vector<int>& nums) {
        long long int negcunt = 0, poscunt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) poscunt++;
            if(nums[i]<0) negcunt++;
        }
        return max(poscunt,negcunt);
    }
};