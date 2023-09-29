class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc=true,dec=true;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]<nums[i-1]){
                inc=false;
                break;
            }
        }
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]>nums[i-1]){
                dec=false;
                break;
            }
        }
        return inc || dec;
    }
};