class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size();) {
            int correct = nums[i];
            if (nums[i] < nums.size() && nums[i] != nums[correct]) {
                swap(nums[i], nums[correct]);
            } else {
                i++;
            }
        }
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] != i){
                return i;
            }
        }
        return nums.size();
    }
};