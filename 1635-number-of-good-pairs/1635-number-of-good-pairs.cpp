/* Brute force
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int gp=0;
        for(int i=0; i<nums.size(); ++i){
            for(int j=i+1; j<nums.size(); ++j){
                if(nums[i]==nums[j]){
                    gp++;
                }
            }
        }
        return gp;
    }
};
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int arr[101]={0}, gp=0;
        for(int n:nums){
            gp+=arr[n]++;
        }
        return gp;
    }
};