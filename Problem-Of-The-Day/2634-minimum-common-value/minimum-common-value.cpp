class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        /* BRUTE FORCE : O(M*N)
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j]) {
                    return nums1[i]; // Return the common element
                }
            }
        }
        return -1; // No common element found
        */
        unordered_set<int> st(begin(nums1), end(nums1));
        for (int& num : nums2) {
            if (st.find(num) != st.end()) {
                return num;
            }
        }
        return -1;
    }
};