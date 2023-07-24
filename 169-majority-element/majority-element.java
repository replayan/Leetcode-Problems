// variation of the Boyer-Moore Majority Vote algorithm

class Solution {
    public int majorityElement(int[] nums) {
        int candidate = 0;
        int count = 0;
        
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (candidate == num) {
                count++;
            } else {
                count--;
            }
        }
        
        int majorityCount = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == candidate) {
                majorityCount++;
            }
        }
        
        if (majorityCount > nums.length / 2) {
            return candidate;
        } else {
            return -1;
        }
    }
}
