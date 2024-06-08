class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        set<int> st;
        for (int p = 0, i = 0; i < nums.size(); ++i) {
            const int temp = (p + nums[i]) % k;
            if (st.count(temp)) {
                return true;
            }
            st.insert(p);
            p = temp;
        }
        return false;
    }
};