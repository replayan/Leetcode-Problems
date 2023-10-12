/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

// Triple BS \U0001f611

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int start=0;
        int end=mountainArr.length()-1;

        // Okay so we have Find peak element now:
        while(start<end){
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                start=mid+1;
            }else{
                end=mid;
            }
        }

        // Left side BS => left side of the peak for the target
        int peak=start;
        start=0;
        end=peak;
        while(start<=end){
            int mid=start+(end-start)/2;
            int midVal=mountainArr.get(mid);
            if(midVal==target){
                return mid;
            } else if(midVal<target){
                start=mid+1;
            } else{
                end=mid-1;
            }
        }

        // Right side BS => right side of the peak for the target
        start=peak;
        end=mountainArr.length()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int midVal=mountainArr.get(mid);
            if(midVal==target){
                return mid;
            } else if(midVal<target){
                end=mid-1;
            } else{
                start=mid+1;
            }
        }
        return -1;
    }
};