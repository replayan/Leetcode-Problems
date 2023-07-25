class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.length() != t.length()) {
                return false;
            }

            unordered_map<char, int> charFreq;

            for (char c : s) {
                charFreq[c]++;
            }

            for (char c : t) {
                if (charFreq[c] == 0) {
                    return false;
                }
                charFreq[c]--;
            }
            return true;
        }
    };