class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const auto& w : words) {
            int l = 0, r = w.size() - 1;
            while (w[l] == w[r]) {
                if (l >= r) {
                    return w;
                }
                l++;
                r--;
            }
        }
        return "";
    }
};
