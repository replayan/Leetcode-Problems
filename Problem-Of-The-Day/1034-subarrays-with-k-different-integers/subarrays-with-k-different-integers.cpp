class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int res = 0;
        int left_near = 0;
        int left_far = 0;
        for (int right = 0; right < nums.size(); right++) {
            count[nums[right]] += 1;

            while (count.size() > k) {
                count[nums[left_near]] -= 1;
                if (count[nums[left_near]] == 0) {
                    count.erase(nums[left_near]);
                }
                left_near += 1;
                left_far = left_near;
            }

            while (count[nums[left_near]] > 1) {
                count[nums[left_near]] -= 1;
                left_near += 1;
            }

            if (count.size() == k) {
                res += left_near - left_far + 1;
            }
        }
        return res;
    }
};