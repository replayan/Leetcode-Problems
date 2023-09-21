class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArr;
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(mergedArr));
        int n = mergedArr.size();
        if (n % 2 == 0) {
            return (mergedArr[n / 2 - 1] + mergedArr[n / 2]) / 2.0;
        } else {
            return mergedArr[n / 2];
        }
    }
};
