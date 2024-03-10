class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // (A ∩ B) is the set of all the elements that are common to both sets A
        // and B.
        // unordered_set<int> st1(nums1.begin(), nums1.end());
        // unordered_set<int> st2(nums2.begin(), nums2.end());
        // vector<int> res;
        // for (auto const& num : st1) {
        //     if (st2.find(num) != st2.end()) {
        //         res.push_back(num);
        //     }
        // }
        // return res;

        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2;
        for (auto const& num : nums2) {
            if (st1.find(num) != st1.end()) {
                st2.insert(num);
            }
        }
        vector<int> res(st2.begin(), st2.end());
        return res;
    }
};