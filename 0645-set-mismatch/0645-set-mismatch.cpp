class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), i=0;
        while(i < n){
            int correctIndex = nums[i]-1;
            if(nums[i] != nums[correctIndex]){
                swap(nums[i],nums[correctIndex]);
            } else {
                i++;
            }
        }
        for (int index=0; index<n; index++) {
            if (nums[index] != index + 1) {
                return {nums [index], index + 1};
            }
        }
        return {-1, -1};
    }
};