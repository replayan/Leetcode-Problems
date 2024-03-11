class Solution {
public:
    string customSortString(string order, string s) {
        int count[26] = {0};
        for (char& ch : s) {
            count[ch - 'a']++;
        }
        string res = "";
        for (char& ch : order) {
            while (count[ch - 'a']--) {
                res.push_back(ch);
            }
        }
        for (char& ch : s) {
            if (count[ch - 'a'] > 0) {
                res.push_back(ch);
            }
        }
        return res;
    }
};