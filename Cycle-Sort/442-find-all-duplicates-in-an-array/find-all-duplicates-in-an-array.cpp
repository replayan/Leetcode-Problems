class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size(), i=0;
        while(i < n){
            int correctIndex = nums[i]-1;
            if(nums[i] != nums[correctIndex]){
                swap(nums[i],nums[correctIndex]);
            } else {
                i++;
            }
        }
        vector<int> nums2;
        for(int i=0; i<n; i++){
            if(nums[i] != i+1){
                nums2.push_back(nums[i]);
            }
        }
        return nums2;
    }
};