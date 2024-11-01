class Solution {
public:
    string makeFancyString(string s) {
        string res;
        for (int i = 0; i < size(s); ++i) {
            int length = size(res);
            if (length >= 2 && res[length - 1] == s[i] && res[length - 2] == s[i]) {
                continue;
            }
            res += s[i]; 
        }
        return res;
    }
};
