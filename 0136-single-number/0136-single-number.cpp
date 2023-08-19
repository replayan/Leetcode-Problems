// Brute force approach

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            bool duplicate=false;
            for(int j=0; j<n; j++){
                if(i != j && nums[j]==nums[i]){
                    duplicate=true;
                    break;
                }
            }
            if(!duplicate){
                return nums[i];
            }
        }
        throw invalid_argument("No single number found.");
    }
};