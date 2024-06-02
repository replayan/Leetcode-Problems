class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = size(s) - 1;
        while (left < right) {
            if (s[right] != s[left]) {
                swap(s[right], s[left]);
            }
            left++;
            right--;
        }
    }
};