class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() == t.length()) {
            vector<int> mp1(256, -1);
            vector<int> mp2(256, -1);
            for (int i = 0; i < s.size(); ++i) {
                int c1 = s[i];
                int c2 = t[i];

                // If neither character is mapped yet
                if (mp1[c1] == -1 && mp2[c2] == -1) {
                    mp1[c1] = c2; // Map c1 to c2 in mp1
                    mp2[c2] = c1; // Map c2 to c1 in mp2
                }
                // If the mapping is invalid
                else if (mp1[c1] != c2 || mp2[c2] != c1) {
                    return false; // Strings are not isomorphic
                }
            }
        }
        return true; // Strings are isomorphic
    }
};