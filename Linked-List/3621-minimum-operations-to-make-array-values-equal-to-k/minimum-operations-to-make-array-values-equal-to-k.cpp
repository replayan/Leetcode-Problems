class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int num : nums) {
            if (num < k) {
                return -1;
            }
        }

        int operations = 0;

        while (true) {
            bool all_k = true;
            for (int num : nums) {
                if (num != k) {
                    all_k = false;
                    break;
                }
            }
            if (all_k) {
                return operations;
            }

            int max_val = nums[0];
            for (int num : nums) {
                if (num > max_val) {
                    max_val = num;
                }
            }

            int second_max = k;
            for (int num : nums) {
                if (num > second_max && num < max_val) {
                    second_max = num;
                }
            }

            int h = second_max;
            for (int num : nums) {
                if (num > h && num != max_val) {
                    h = max_val - 1;
                    break;
                }
            }

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > h) {
                    nums[i] = h;
                }
            }
            operations++;
        }

        return operations;
    }
};
