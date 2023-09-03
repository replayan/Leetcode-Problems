/* => order agnostic binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;
        bool isAsc=nums[start]<nums[end];
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target) return mid;

            if(isAsc){
                if(target>nums[mid]){
                    start=mid+1;
                } 
                else {
                    end=mid-1;
                }
            }else{
                if(target<nums[mid]){
                    start=mid+1;
                }
                else {
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};
*/

// BS using recursion
class Solution{
public:
    int search(vector<int>& nums, int target){
        return bS(nums,target,0,nums.size()-1);
    }
    int bS(vector<int> nums,int target,int start,int end){
        if(start<=end){ 
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                return bS(nums,target,mid+1,end);
            }else{
                return bS(nums,target,start,mid-1);
            }
        }
        return -1;
    }
};
