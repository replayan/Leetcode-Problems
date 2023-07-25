class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> charCount(26, 0);

        for (int i = 0; i < s.length(); i++) {
            charCount[s[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            charCount[t[i] - 'a']--;
        }

        for (int count : charCount) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};