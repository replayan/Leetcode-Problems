class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg, pos;
        int i = 0;
        for (int n : nums) {
            if (n > 0)
                pos.push_back(n);
            else
                neg.push_back(n);
        }
        while (2 * i < nums.size()) {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
            ++i;
        }
        return nums;
    }
};
