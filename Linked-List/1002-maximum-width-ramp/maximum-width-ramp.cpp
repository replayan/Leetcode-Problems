class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[i] < nums[s.top()]) {
                s.push(i);
            }
        }
        int r = 0;
        for (int j = n - 1, m = -1; !s.empty() && j >= 0; --j) {
            while (!s.empty() && s.top() >= j) {
                s.pop();
            }
            if (nums[j] > m) {
                m = nums[j];
                while (!s.empty() && nums[j] >= nums[s.top()]) {
                    r = max(r, j - s.top());
                    s.pop();
                }
            }
        }
        return r;
    }
};