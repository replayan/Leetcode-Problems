class Solution {
public:
    string customSortString(string order, string s) {
        /* freq counting
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
        */

        // using custom comparator
        vector<int> mp(26, -1);
        for (int i = 0; i < order.size(); ++i) {
            char ch = order[i];
            mp[ch - 'a'] = i;
        }
        auto myComparator = [&mp](char& ch1, char& ch2) {
            if (mp[ch1 - 'a'] < mp[ch2 - 'a']) {
                return true;
            } else {
                return false;
            }
        };
        sort(begin(s), s.end(), myComparator);
        return s;
    }
};