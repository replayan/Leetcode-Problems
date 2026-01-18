class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> frequency;

        for (char c : s) {
            frequency[c]++;
        }

        for (char c : t) {
            if (--frequency[c] < 0) {
                return false;
            }
        }

        return true;
    }
};
