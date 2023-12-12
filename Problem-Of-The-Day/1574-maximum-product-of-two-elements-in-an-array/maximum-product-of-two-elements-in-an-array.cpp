class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),maxVal=1;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                maxVal=max(maxVal, (nums[j]-1)*(nums[i]-1));
            }
        }
        if (nums[n-1]==1 && nums[n-2]==1) {
            return 0;
        }
        return maxVal;
    }
};