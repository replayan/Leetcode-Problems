/*
// LC problem of the day

cycle sort:->

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
*/

// fast & slow pointer :->

class Solution{
public:
    int findDuplicate(vector<int>& nums){
        int slow=0,fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        } while(slow!=fast);
        slow=0; // reset the slow to detect meet point
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};