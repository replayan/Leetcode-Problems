// variation of the Boyer-Moore Majority Vote algorithm
// TC: O(N) SC: O(1)

class Solution {
    public int majorityElement(int[] nums) {
        int majorityElement = 0;
        int count = 0;
        
        for (int num : nums) {
            // int num = nums[i];
            if (count == 0) {
                majorityElement = num;
                count = 1;
            } else if (majorityElement == num) {
                count++;
            } else {
                count--;
            }
        }
        
        int majorityElementCount = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == majorityElement) {
                majorityElementCount++;
            }
        }
        
        if (majorityElementCount > nums.length / 2) {
            return majorityElement;
        } else {
            return -1;
        }
    }
}

