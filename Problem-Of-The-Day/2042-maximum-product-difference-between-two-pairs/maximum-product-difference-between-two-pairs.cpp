// BRUTE FORCE N(LOGn)

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        long long int w=nums[n-1];
        long long int x=nums[n-2];
        long long int y=nums[0];
        long long int z=nums[1];
        long long int maxi=(w*x) - (y*z);
        return maxi;
    }
};
