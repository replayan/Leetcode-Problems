class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for (int x : arr2) {
            for (int len = to_string(x).length(); len; x /= 10, --len) {
                s.insert(x);
            }
        }
        int r = 0;
        for (int x : arr1) {
            for (int len = to_string(x).length(); len > r; x /= 10, --len) {
                if (s.count(x)) {
                    r = len;
                    break;
                }
            }
        }
        return r;
    }
};