class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int r = -1;
        vector<bool> v(1024);
        for (int x : nums) {
            if (x > 0) {
               v[x] = true;
            }
        }
        for (int x : nums) {
            if (x < 0 && v[-x]) {
                r = max(r, -x);
            }
        }
        return r;
    }
};