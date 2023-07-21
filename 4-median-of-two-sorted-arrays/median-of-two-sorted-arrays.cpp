class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(merged));

        int size = merged.size();
        if (size % 2 == 0) {
            return (static_cast<double>(merged[size / 2 - 1]) + static_cast<double>(merged[size / 2])) / 2.0;
        } else {
            return static_cast<double>(merged[size / 2]);
        }
    }
};