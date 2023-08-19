// Brute force approach

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    //     int n=nums.size();
    //     for(int i=0; i<n; i++){
    //         bool duplicate=false;
    //         for(int j=0; j<n; j++){
    //             if(i != j && nums[j]==nums[i]){
    //                 duplicate=true;
    //                 break;
    //             }
    //         }
    //         if(!duplicate){
    //             return nums[i];
    //         }
    //     }
    //     throw invalid_argument("No single number found.");
    // }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i+=2) {
            if (i + 1 >= nums.size() || nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        throw invalid_argument("No single number found.");
    }
};