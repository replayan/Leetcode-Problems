class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int totalSize = m + n;
        int midIndex = totalSize / 2;
        int i = 0, j = 0;
        vector<int> merged;

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            merged.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            merged.push_back(nums2[j]);
            j++;
        }

        if (totalSize % 2 == 0) {
            return (static_cast<double>(merged[midIndex - 1]) + static_cast<double>(merged[midIndex])) / 2.0;
        } else {
            return static_cast<double>(merged[midIndex]);
        }
    }
};