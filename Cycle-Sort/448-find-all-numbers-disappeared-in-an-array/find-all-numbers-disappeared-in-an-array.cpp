class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Use cycle sort
        for (int i = 0; i < nums.size();) {
            int correct = nums[i]-1;
            if (nums[i] != nums[correct]) {
                swap(nums[i], nums[correct]);
            } else {
                i++;
            }
        }
        // find missing numbers
        vector<int> disappear;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] != i+1){
                disappear.push_back(i+1);
            }
        }
        return disappear;
    }
};