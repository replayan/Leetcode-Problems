class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = size(s) - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                swap(s[left], s[right]);
            }
            left += 1;
            right -= 1;
        }
    }
};