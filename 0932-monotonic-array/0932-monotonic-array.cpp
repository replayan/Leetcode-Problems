class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc=true,dec=true;
        int n=nums.size()-1;
        for(int i=0; i<n; ++i){
            if(nums[i]<nums[i+1]){
                inc=false;
                break;
            }
        }
        for(int i=0; i<n; ++i){
            if(nums[i]>nums[i+1]){
                dec=false;
                break;
            }
        }
        return inc || dec;
    }
};