class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0]; // eliminating the first element
        if(nums[n-1]!=nums[n-2]) return nums[n-1]; // eliminating the last element

        int start=1;
        int end=n-2;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            } else if((mid%2 == 1 && nums[mid]==nums[mid-1]) // left part
            || (mid%2 == 0 && nums[mid]==nums[mid+1])){
                start=mid+1;
            } else{
                end=mid-1; // right part
            }
        }
        return -1;
    }
};