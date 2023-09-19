// LC problem of the day
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(),i=0;
        while(i<n){
            if(nums[i]!=i+1){
                int corrt=nums[i]-1;
                if(nums[i]!=nums[corrt]){
                    swap(nums[corrt],nums[i]);
                } else{
                    return nums[i];
                }
            } else{
                i++;
            }
        }
        return -1;
    }
};