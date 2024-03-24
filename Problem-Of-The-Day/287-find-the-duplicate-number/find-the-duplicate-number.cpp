class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /* BRUTE FORCE : TLE\U0001f612
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
        return -1;
        */

        /* Floyd's cycle-finding algorithm : TC => O(n), SC => O(1)
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        */

        // using cycle sort TC => O(n), SC => O(1)
        for (int i = 0; i < nums.size();) {
            if (nums[i] != i + 1) {
                int correct_index = nums[i] - 1;
                if (nums[correct_index] != nums[i]) {
                    swap(nums[i], nums[correct_index]);
                } else {
                    return nums[i];
                }
            } else {
                i++;
            }
        }
        return -1;
    }
};