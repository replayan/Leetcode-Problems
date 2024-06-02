class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = size(s) - 1;
        for (; left <= right;) {
            if (s[left] != s[right]) {
                swap(s[left], s[right]);
            }
            left++;
            right--;
        }
    }
};