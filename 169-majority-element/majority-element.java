// BRUTE FORCE APPROACH
// TC: O(N^2)

class Solution {
    public int majorityElement(int[] nums) {
        int majorityCount = nums.length / 2;
        
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int count = 0;
            for (int j = 0; j < nums.length; j++) {
                if (nums[j] == num) {
                    count++;
                }
            }
            if (count > majorityCount) {
                return num;
            }
        }
        return -1;
    }
}
