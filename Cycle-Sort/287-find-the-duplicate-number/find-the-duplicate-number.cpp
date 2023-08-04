class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(),i = 0;
        while(i < n){
            if(nums[i] != i+1){
                int correct = nums[i]-1;
                if(nums[i] != nums[correct]){
                    swap(nums[i],nums[correct]);
                } else{
                    return nums[i];
                }
            } else {
                i++;
            }
        }
        return -1;
    }
};